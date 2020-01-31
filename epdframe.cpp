#if (defined(__AVR__))
#include <avr\pgmspace.h>
#else
#include <pgmspace.h>
#endif
#include "epdframe.h"
#include <math.h>

/**
 * @brief Instantiates a new epdframe. This will save the data of the frame.
 * 
 * @param   background_color
 *          Backaground color of the screen (BLACK or WHITE)
 * @param   scr_width
 *          Number of pixels on the Y axis of the screen.
 * @param   scr_height
 *          Number of pixels on the X axis of the screen.
 * */

epdframe::epdframe(uint8_t background_color, uint16_t scr_width, uint16_t scr_height){
    this->scr_width=scr_width;
    this->scr_height=scr_height;
    this->background_color=background_color;
}

epdframe::~epdframe(){

}

/**
 * @brief Perform the hardware initalization of the screen
 * 
 * @return 1 if the initialization succed otherwise will return 0
 * */

uint8_t epdframe::init_screen(){
    // Init the screen
    if (this->epd.Init_fastRefresh() != 0) {
        Serial.print("e-Paper init failed");
        this->~epdframe();
        return 0;
    }

    // Wipe the buffer and the screen image
    this->wipe_buffer();
    this->clear_screen();
    return 1;
}

/**
 * @brief This function save the data saved on the buffer.
 * **/

void epdframe::show(){
    //This is "trick" to allow partial refresh. Just modify the buffer that we want to send, and set the partial screen the full size of the screen.
    this->epd.SetPartialWindow(this->frame_buffer,0,0,this->scr_width,this->scr_height,2);
    this->epd.DisplayFrameQuick();
    this->epd.WaitUntilIdle();
}

/**
 * @brief This functions wipe the buffer data, setting all the positions to white.
 * */

void epdframe::wipe_buffer(){
    //This wipe the content of the buffer frame, setting all the positions on white.
    for (int x = 0; x < this->scr_width; x++) {
        for (int y = 0; y < this->scr_height; y++) {
            this->frame_buffer[(x + y * this->scr_width) / 8] |= 0x80 >> (x % 8);
        }
    }
}

/**
 * @brief Clear the images on the screen.
 * */

void epdframe::clear_screen(){
    //Execute the clear command of the screen, wiping all the screen.
    this->epd.ClearFrame();
}


