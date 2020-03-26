#include "epd42_logic.h"

epd42::epd42(){
    this->scr_height=SCR_HEIGHT;
    this->scr_width=SCR_WIDTH;
    this->x_origin=0;
    this->y_origin=0;
    this->scr_dtm=SCR_DTM;
}

epd42::~epd42(){}

uint8_t epd42::epd_init(){
    
    //Init hardware bus and peripherals
    dev_init();

    //Reset the screen
    reset();

    // Start screen configuration process
    send_command(POWER_SETTING);
    send_data(0x03);                  // VDS_EN, VDG_EN
    send_data(0x00);                  // VCOM_HV, VGHL_LV[1], VGHL_LV[0]
    send_data(0x2b);                  // VDH
    send_data(0x2b);                  // VDL
    send_data(0xff);                  // VDHR
    send_command(BOOSTER_SOFT_START);
    send_data(0x17);
    send_data(0x17);
    send_data(0x17);                  //07 0f 17 1f 27 2F 37 2f
    send_command(POWER_ON);
    this->dev_idle();
    send_command(PANEL_SETTING);
	send_data(0x3F); //300x400 B/W mode, LUT set by register

    send_command(PLL_CONTROL);
    send_data(0x3A);        // 3A 100Hz   29 150Hz   39 200Hz    31 171Hz       3C 50Hz (default)    0B 10Hz

    return 0;
}

void epd42::save_data(const unsigned char* frame_buffer){
    send_command(PARTIAL_IN);
    send_command(PARTIAL_WINDOW);
    send_data(this->x_origin >> 8);
    send_data(this->x_origin & 0xf8);     // x should be the multiple of 8, the last 3 bit will always be ignored
    send_data(((this->x_origin & 0xf8) + this->scr_width  - 1) >> 8);
    send_data(((this->x_origin & 0xf8) + this->scr_width  - 1) | 0x07);
    send_data(this->y_origin >> 8);        
    send_data(this->y_origin & 0xff);
    send_data((this->y_origin + this->scr_height - 1) >> 8);        
    send_data((this->y_origin + this->scr_height - 1) & 0xff);
    send_data(0x01);         // Gates scan both inside and outside of the partial window. (default) 
    delay(2);
    send_command((this->scr_dtm == 1) ? DATA_START_TRANSMISSION_1 : DATA_START_TRANSMISSION_2);
    if (frame_buffer != NULL) {
        for(int i = 0; i < this->scr_width  / 8 * this->scr_height; i++) {
            send_data(frame_buffer[i]);  
        }  
    } else {
        for(int i = 0; i < this->scr_height  / 8 * this->scr_width; i++) {
            send_data(0x00);  
        }  
    }
    delay(2);
    send_command(PARTIAL_OUT); 
}

void epd42::display_frame(){
    this->set_lut(LUT_FAST);
    send_command(DISPLAY_REFRESH);
}

void epd42::dev_idle(){
    send_command(0x71);
    while(!dev_busy()){
        send_command(0x71);
    }
}

void epd42::clear_frame(){
    send_command(RESOLUTION_SETTING);
    send_data(this->scr_width >> 8);
    send_data(this->scr_width & 0xff);
    send_data(this->scr_height >> 8);        
    send_data(this->scr_height & 0xff);

    send_command(DATA_START_TRANSMISSION_1);           
    delay(2);
    for(int i = 0; i < this->scr_width / 8 * this->scr_height; i++) {
        send_data(0xFF);  
    }  
    delay(2);
    send_command(DATA_START_TRANSMISSION_2);           
    delay(2);
    for(int i = 0; i < this->scr_width / 8 * this->scr_height; i++) {
        send_data(0xFF);  
    }  
    delay(2);
	this->set_lut(LUT_NORMAL);
	send_command(DISPLAY_REFRESH); 
    delay(100);
    this->dev_idle();
}

void epd42::sleep(){
    send_command(VCOM_AND_DATA_INTERVAL_SETTING);
    send_data(0x17);                       //border floating    
    send_command(VCM_DC_SETTING);          //VCOM to 0V
    send_command(PANEL_SETTING);
    delay(100);          

    send_command(POWER_SETTING);           //VG&VS to 0V fast
    send_data(0x00);        
    send_data(0x00);        
    send_data(0x00);              
    send_data(0x00);        
    send_data(0x00);
    delay(100);          
                
    send_command(POWER_OFF);          //power off
    this->dev_idle();
    send_command(DEEP_SLEEP);         //deep sleep
    send_data(0xA5); 
}

void epd42::set_lut(uint8_t LUT_TYPE){
    unsigned int count;   
    if(LUT_TYPE == LUT_NORMAL){         
        send_command(LUT_FOR_VCOM);                            //vcom
        for(count = 0; count < 44; count++) {
            send_data(lut_vcom0[count]);
        }
        
        send_command(LUT_WHITE_TO_WHITE);                      //ww --
        for(count = 0; count < 42; count++) {
            send_data(lut_ww[count]);
        }   
        
        send_command(LUT_BLACK_TO_WHITE);                      //bw r
        for(count = 0; count < 42; count++) {
            send_data(lut_bw[count]);
        } 

        send_command(LUT_WHITE_TO_BLACK);                      //wb w
        for(count = 0; count < 42; count++) {
            send_data(lut_bb[count]);
        } 

        send_command(LUT_BLACK_TO_BLACK);                      //bb b
        for(count = 0; count < 42; count++) {
            send_data(lut_wb[count]);
        } 
    }
    else{
        send_command(LUT_FOR_VCOM);                            //vcom
        for(count = 0; count < 44; count++) {
            send_data(lut_vcom0_quick[count]);
        }
        
        send_command(LUT_WHITE_TO_WHITE);                      //ww --
        for(count = 0; count < 42; count++) {
            send_data(lut_ww_quick[count]);
        }   
        
        send_command(LUT_BLACK_TO_WHITE);                      //bw r
        for(count = 0; count < 42; count++) {
            send_data(lut_bw_quick[count]);
        } 

        send_command(LUT_WHITE_TO_BLACK);                      //wb w
        for(count = 0; count < 42; count++) {
            send_data(lut_wb_quick[count]);
        } 

        send_command(LUT_BLACK_TO_BLACK);                      //bb b
        for(count = 0; count < 42; count++) {
            send_data(lut_bb_quick[count]);
        } 
    }
}

