#if (defined(__AVR__))
#include <avr\pgmspace.h>
#else
#include <pgmspace.h>
#endif
#include "epdframe.h"
#include <math.h>

#define PI 3.14159265

epdframe::epdframe(uint8_t background_color, uint16_t scr_width, uint16_t scr_height){
    this->scr_width=scr_width;
    this->scr_height=scr_height;
    this->background_color=background_color;
    
    // Init the screen
    if (this->epd.Init_fastRefresh() != 0) {
        Serial.print("e-Paper init failed");
        return;
    }

    // Wipe the buffer and the screen image
    this->wipe_buffer();
    this->clear_screen();
}

epdframe::~epdframe(){
    this->wipe_buffer();
    this->clear_screen();
}

void epdframe::show(){
    this->epd.SetPartialWindow(this->frame_buffer,0,0,this->scr_width,this->scr_height,2);
    this->epd.DisplayFrameQuick();
    this->epd.WaitUntilIdle();
}

void epdframe::wipe_buffer(){
    //This wipe the content of the buffer frame
    for (int x = 0; x < this->scr_width; x++) {
        for (int y = 0; y < this->scr_height; y++) {
            this->frame_buffer[(x + y * this->scr_width) / 8] |= 0x80 >> (x % 8);
        }
    }
}

void epdframe::clear_screen(){
    //This delete content of the screen
    this->epd.ClearFrame();
}


/*void epdframe::calculate_buffer_size(){
    this->buffer_size=(this->scr_width + this->scr_height*this->scr_width)/8;
    if (this->epd.Init_fastRefresh() != 0) {
        Serial.print("e-Paper init failed");
        return;
    }
    Serial.println("Init correc \r\n");
    this->epd.ClearFrame();
}*/
