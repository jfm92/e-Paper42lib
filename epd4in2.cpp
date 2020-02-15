/**
 *  @filename   :   epd4in2.cpp
 *  @brief      :   Implements for Dual-color e-paper library
 *  @author     :   Yehui from Waveshare
 *
 *  Copyright (C) Waveshare     August 10 2017
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documnetation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to  whom the Software is
 * furished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdlib.h>
#include "epd4in2.h"

Epd::~Epd() {
};

Epd::Epd() {
    reset_pin = RST_PIN;
    dc_pin = DC_PIN;
    cs_pin = CS_PIN;
    busy_pin = BUSY_PIN;
    din_pin = DIN_PIN;
    sck_pin = SCK_PIN;
    width = EPD_WIDTH;
    height = EPD_HEIGHT;
};

int Epd::Init_fastRefresh(void) {
    /* this calls the peripheral hardware interface, see epdif */
   
    if (IfInit() != 0) {
        return -1;
    }
    /* EPD hardware init start */

    Reset();
    SendCommand(POWER_SETTING);
    SendData(0x03);                  // VDS_EN, VDG_EN
    SendData(0x00);                  // VCOM_HV, VGHL_LV[1], VGHL_LV[0]
    SendData(0x2b);                  // VDH
    SendData(0x2b);                  // VDL
    SendData(0xff);                  // VDHR
    SendCommand(BOOSTER_SOFT_START);
    SendData(0x17);
    SendData(0x17);
    SendData(0x17);                  //07 0f 17 1f 27 2F 37 2f
    SendCommand(POWER_ON);
    WaitUntilIdle();
    SendCommand(PANEL_SETTING);
	SendData(0x3F); //300x400 B/W mode, LUT set by register

    SendCommand(PLL_CONTROL);
    SendData(0x3A);        // 3A 100Hz   29 150Hz   39 200Hz    31 171Hz       3C 50Hz (default)    0B 10Hz
    /* EPD hardware init end */
    return 0;
}



/**
 *  @brief: basic function for sending commands
 */
void Epd::SendCommand(unsigned char command) {
  digitalWrite(dc_pin, LOW);
    digitalWrite(cs_pin, LOW);

    for (int i = 0; i < 8; i++)
    {
        if ((command & 0x80) == 0) digitalWrite(din_pin, LOW); 
        else                    digitalWrite(din_pin, HIGH);

        command <<= 1;
        digitalWrite(sck_pin, HIGH);
        digitalWrite(sck_pin, LOW);
    }
    
    //SPI.transfer(data);
    digitalWrite(cs_pin, HIGH);
}

/**
 *  @brief: basic function for sending data
 */
void Epd::SendData(unsigned char data) {
  digitalWrite(dc_pin, HIGH);
    digitalWrite(cs_pin, LOW);

    for (int i = 0; i < 8; i++)
    {
        if ((data & 0x80) == 0) digitalWrite(din_pin, LOW); 
        else                    digitalWrite(din_pin, HIGH);

        data <<= 1;
        digitalWrite(sck_pin, HIGH);
        digitalWrite(sck_pin, LOW);
    }
    
    //SPI.transfer(data);
    digitalWrite(cs_pin, HIGH);
}

/**
 *  @brief: Wait until the busy_pin goes HIGH
 */
void Epd::WaitUntilIdle(void) {
	SendCommand(0x71);
    while(DigitalRead(busy_pin) == 0) {      //0: busy, 1: idle
        DelayMs(100);
		SendCommand(0x71);
    }      
}

/**
 *  @brief: module reset. 
 *          often used to awaken the module in deep sleep, 
 *          see Epd::Sleep();
 */
void Epd::Reset(void) {
    DigitalWrite(reset_pin, LOW);
    DelayMs(200);
    DigitalWrite(reset_pin, HIGH);
    DelayMs(200);   
}

/**
 *  @brief: transmit partial data to the SRAM
 */
void Epd::SetPartialWindow(const unsigned char* buffer_black, int x, int y, int w, int l, int dtm) {
    SendCommand(PARTIAL_IN);
    SendCommand(PARTIAL_WINDOW);
    SendData(x >> 8);
    SendData(x & 0xf8);     // x should be the multiple of 8, the last 3 bit will always be ignored
    SendData(((x & 0xf8) + w  - 1) >> 8);
    SendData(((x & 0xf8) + w  - 1) | 0x07);
    SendData(y >> 8);        
    SendData(y & 0xff);
    SendData((y + l - 1) >> 8);        
    SendData((y + l - 1) & 0xff);
    SendData(0x01);         // Gates scan both inside and outside of the partial window. (default) 
    DelayMs(2);
    SendCommand((dtm == 1) ? DATA_START_TRANSMISSION_1 : DATA_START_TRANSMISSION_2);
    if (buffer_black != NULL) {
        for(int i = 0; i < w  / 8 * l; i++) {
            SendData(buffer_black[i]);  
        }  
    } else {
        for(int i = 0; i < w  / 8 * l; i++) {
            SendData(0x00);  
        }  
    }
    DelayMs(2);
    SendCommand(PARTIAL_OUT);  
}

/**
 *  @brief: set the look-up table
 */
void Epd::SetLut(void) {
    unsigned int count;     
    SendCommand(LUT_FOR_VCOM);                            //vcom
    for(count = 0; count < 44; count++) {
        SendData(lut_vcom0[count]);
    }
    
    SendCommand(LUT_WHITE_TO_WHITE);                      //ww --
    for(count = 0; count < 42; count++) {
        SendData(lut_ww[count]);
    }   
    
    SendCommand(LUT_BLACK_TO_WHITE);                      //bw r
    for(count = 0; count < 42; count++) {
        SendData(lut_bw[count]);
    } 

    SendCommand(LUT_WHITE_TO_BLACK);                      //wb w
    for(count = 0; count < 42; count++) {
        SendData(lut_bb[count]);
    } 

    SendCommand(LUT_BLACK_TO_BLACK);                      //bb b
    for(count = 0; count < 42; count++) {
        SendData(lut_wb[count]);
    } 
}

/**
 *  @brief: set the look-up table for quick display (partial refresh)
 */

void Epd::SetLutQuick(void) {
    unsigned int count;     
    SendCommand(LUT_FOR_VCOM);                            //vcom
    for(count = 0; count < 44; count++) {
        SendData(lut_vcom0_quick[count]);
    }
    
    SendCommand(LUT_WHITE_TO_WHITE);                      //ww --
    for(count = 0; count < 42; count++) {
        SendData(lut_ww_quick[count]);
    }   
    
    SendCommand(LUT_BLACK_TO_WHITE);                      //bw r
    for(count = 0; count < 42; count++) {
        SendData(lut_bw_quick[count]);
    } 

    SendCommand(LUT_WHITE_TO_BLACK);                      //wb w
    for(count = 0; count < 42; count++) {
        SendData(lut_wb_quick[count]);
    } 

    SendCommand(LUT_BLACK_TO_BLACK);                      //bb b
    for(count = 0; count < 42; count++) {
        SendData(lut_bb_quick[count]);
    } 
}

/**
 * @brief: clear the frame data from the SRAM, this won't refresh the display
 */
void Epd::ClearFrame(void) {
    SendCommand(RESOLUTION_SETTING);
    SendData(width >> 8);
    SendData(width & 0xff);
    SendData(height >> 8);        
    SendData(height & 0xff);

    SendCommand(DATA_START_TRANSMISSION_1);           
    DelayMs(2);
    for(int i = 0; i < width / 8 * height; i++) {
        SendData(0xFF);  
    }  
    DelayMs(2);
    SendCommand(DATA_START_TRANSMISSION_2);           
    DelayMs(2);
    for(int i = 0; i < width / 8 * height; i++) {
        SendData(0xFF);  
    }  
    DelayMs(2);
	SetLut();
	SendCommand(DISPLAY_REFRESH); 
    DelayMs(100);
    WaitUntilIdle();
}


void Epd::DisplayFrameQuick(void) {
    SetLutQuick();
    SendCommand(DISPLAY_REFRESH); 
}

/**
 * @brief: After this command is transmitted, the chip would enter the deep-sleep mode to save power. 
 *         The deep sleep mode would return to standby by hardware reset. The only one parameter is a 
 *         check code, the command would be executed if check code = 0xA5. 
 *         You can use Epd::Reset() to awaken and use Epd::Init() to initialize.
 */
void Epd::Sleep() {
    SendCommand(VCOM_AND_DATA_INTERVAL_SETTING);
    SendData(0x17);                       //border floating    
    SendCommand(VCM_DC_SETTING);          //VCOM to 0V
    SendCommand(PANEL_SETTING);
    DelayMs(100);          

    SendCommand(POWER_SETTING);           //VG&VS to 0V fast
    SendData(0x00);        
    SendData(0x00);        
    SendData(0x00);              
    SendData(0x00);        
    SendData(0x00);
    DelayMs(100);          
                
    SendCommand(POWER_OFF);          //power off
    WaitUntilIdle();
    SendCommand(DEEP_SLEEP);         //deep sleep
    SendData(0xA5);
}

const unsigned char lut_vcom0[] =
{
0x00, 0x17, 0x00, 0x00, 0x00, 0x02,        
0x00, 0x17, 0x17, 0x00, 0x00, 0x02,        
0x00, 0x0A, 0x01, 0x00, 0x00, 0x01,        
0x00, 0x0E, 0x0E, 0x00, 0x00, 0x02,        
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

};
const unsigned char lut_ww[] ={
0x40, 0x17, 0x00, 0x00, 0x00, 0x02,
0x90, 0x17, 0x17, 0x00, 0x00, 0x02,
0x40, 0x0A, 0x01, 0x00, 0x00, 0x01,
0xA0, 0x0E, 0x0E, 0x00, 0x00, 0x02,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

};
const unsigned char lut_bw[] ={
0x40, 0x17, 0x00, 0x00, 0x00, 0x02,
0x90, 0x17, 0x17, 0x00, 0x00, 0x02,
0x40, 0x0A, 0x01, 0x00, 0x00, 0x01,
0xA0, 0x0E, 0x0E, 0x00, 0x00, 0x02,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      
};

const unsigned char lut_bb[] ={
0x80, 0x17, 0x00, 0x00, 0x00, 0x02,
0x90, 0x17, 0x17, 0x00, 0x00, 0x02,
0x80, 0x0A, 0x01, 0x00, 0x00, 0x01,
0x50, 0x0E, 0x0E, 0x00, 0x00, 0x02,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
             
};

const unsigned char lut_wb[] ={
0x80, 0x17, 0x00, 0x00, 0x00, 0x02,
0x90, 0x17, 0x17, 0x00, 0x00, 0x02,
0x80, 0x0A, 0x01, 0x00, 0x00, 0x01,
0x50, 0x0E, 0x0E, 0x00, 0x00, 0x02,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            
};

/*********************Quick LUT***********************/

const unsigned char lut_vcom0_quick[] =
{
0x00, 0x0E, 0x00, 0x00, 0x00, 0x01,        
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const unsigned char lut_ww_quick[] ={
0xA0, 0x0E, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const unsigned char lut_bw_quick[] ={
0xA0, 0x0E, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     
};

const unsigned char lut_bb_quick[] ={
0x50, 0x0E, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     
};

const unsigned char lut_wb_quick[] ={
0x50, 0x0E, 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         
};

/* END OF FILE */
