#include "epdframe.h"

image::image(uint16_t x_pos, uint16_t y_pos, const unsigned char *image_buffer, uint16_t img_width, uint16_t img_height){
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->image_width = img_width;
    this->image_heigth = img_height;
    this->image_buffer=image_buffer;
    
}

image::~image(){

}

void image::save_image(epdframe &frame){
    for (int x = 0; x < this->image_width; x++) {
        for (int y = 0; y < this->image_heigth; y++) {
            frame.frame_buffer[((x+this->x_pos) + (y+this->y_pos) * frame.scr_width) / 8] = this->image_buffer[(x + y * this->image_width) / 8];
        }
    }
}

void image::delete_image(epdframe &frame){
    for (int x = 0; x < this->image_width; x++) {
        for (int y = 0; y < this->image_heigth; y++) {
            if(this->image_buffer[(x + y * this->image_width) / 8]!= 0xff){
                frame.frame_buffer[((x+this->x_pos) + (y+this->y_pos) * frame.scr_width) / 8] = 0xff;
            }
        }
    }
}

uint16_t image::get_x_pos(){
    return this->x_pos;
}

uint16_t image::get_y_pos(){
    return this->y_pos;
}

uint16_t image::get_image_heigth(){
    return this->image_heigth;
}

uint16_t image::get_image_width(){
    return this->image_width;
}

void image::set_x_pos(uint16_t x_pos){
    this->x_pos=x_pos;
}

void image::set_y_pos(uint16_t y_pos){
    this->y_pos=y_pos;
}