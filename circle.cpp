#include "epdframe.h"

circle::circle(uint16_t x_pos, uint16_t y_pos, uint16_t circle_radius, uint8_t color, bool filled){
    this->x_pos=x_pos;
    this->y_pos=y_pos;
    this->radius=circle_radius;
    this->color=color;
    this->filled=filled;
}

circle::~circle(){

}
/**
 * @brief
 * */
void circle::save_figure(epdframe &frame){
    int x_pos = -this->radius;
    int y_pos = 0;
    int err = 2 - 2 * this->radius;
    int e2;

    do {
        if(this->color==BLACK){
            frame.frame_buffer[((this->x_pos-x_pos) + (this->y_pos+y_pos) * frame.scr_width) / 8] &= ~(0x80 >> ((this->x_pos-x_pos) % 8));
            frame.frame_buffer[((this->x_pos+x_pos) + (this->y_pos+y_pos) * frame.scr_width) / 8] &= ~(0x80 >> ((this->x_pos+x_pos) % 8));
            frame.frame_buffer[((this->x_pos+x_pos) + (this->y_pos-y_pos) * frame.scr_width) / 8] &= ~(0x80 >> ((this->x_pos+x_pos) % 8));
            frame.frame_buffer[((this->x_pos-x_pos) + (this->y_pos-y_pos) * frame.scr_width) / 8] &= ~(0x80 >> ((this->x_pos-x_pos) % 8));
            if(this->filled==true){
                //TODO:Add filled circle
            }
        }
        else{
            frame.frame_buffer[((this->x_pos-x_pos) + (this->y_pos+y_pos) * frame.scr_width) / 8] |= 0x80 >> ((this->x_pos-x_pos) % 8);
            frame.frame_buffer[((this->x_pos+x_pos) + (this->y_pos+y_pos) * frame.scr_width) / 8] |= 0x80 >> ((this->x_pos+x_pos) % 8);
            frame.frame_buffer[((this->x_pos+x_pos) + (this->y_pos-y_pos) * frame.scr_width) / 8] |= 0x80 >> ((this->x_pos+x_pos) % 8);
            frame.frame_buffer[((this->x_pos-x_pos) + (this->y_pos-y_pos) * frame.scr_width) / 8] |= 0x80 >> ((this->x_pos-x_pos) % 8);
            if(this->filled==true){
                //TODO:Add filled circle
            }
        }
        
        e2 = err;
        if (e2 <= y_pos) {
            err += ++y_pos * 2 + 1;
            if(-x_pos == y_pos && e2 <= x_pos) {
              e2 = 0;
            }
        }
        if (e2 > x_pos) {
            err += ++x_pos * 2 + 1;
        }
    } while (x_pos <= 0);
}

void circle::delete_figure(epdframe &frame){
    this->color=!this->color; // We change the color to the opposite
    this->save_figure(frame); // Repaint the figure on the opposite color.
    this->color=!this->color; // Set to the original color, if we want to repaint on the future.
}


/**
 * @brief Return the X position of the figure.
 * 
 * @return Return an unsigned integer with the X position.
 * */

uint16_t circle::get_x_pos(){
    return this->x_pos;
}

/**
 * @brief Return the Y position of the figure.
 * 
 * @return Return an unsigned integer with the Y position.
 * */

uint16_t circle::get_y_pos(){
    return this->y_pos;
}

/**
 * @brief Return the radius of the circle.
 * 
 * @return Return an unsigned integer with the radius of the circle.
 * */

uint16_t circle::get_radius(){
    return this->radius;
}

/**
 * @brief Return if the circle is filled or not.
 * 
 * @return Return TRUE is the circle is filled otherwise FALSE
 * */

bool circle::get_filled(){
    return this->filled;
}

/**
 * @brief Return the color of the figure.
 * 
 * @return 1 is white and 0 is black.
 * */

uint8_t circle::get_color(){
    return this->color;
}

/**
 * @brief Change the X position of the figure. Is necessary to re-save to see the changes.
 * 
 * @param   x_pos
 *          The new X position of the figure.
 * */

void circle::change_x_pos(uint16_t x_pos){
    this->x_pos=x_pos;
}

/**
 * @brief Change the Y position of the figure. Is necessary to re-save to see the changes.
 * 
 * @param   x_pos
 *          The new Y position of the figure.
 * */

void circle::change_y_pos(uint16_t y_pos){
    this->y_pos=y_pos;
}

/**
 * @brief Change the radius of the circle.
 * 
 * @param   degree
 *          The new radius of the circle.
 * */

void circle::change_radius(uint16_t radius){
    this->radius=radius;
}

/**
 * @brief Change the color of the figure. Is necessary to re-save to see the changes.
 * 
 * @param   color
 *          The new color of the figure. It can be BLACK/WHITE
 * */

void circle::change_color(uint8_t color){
    this->color=color;
}

/**
 * @brief Change to filled or not the figure
 * 
 * @param   filled
 *          True filled the circle or false
 * */

void circle::change_filled(bool filled){
    this->filled=filled;
}