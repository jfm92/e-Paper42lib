#include "epdframe.h"

/**
 * @brief Instantiates a new rectangle class.
 * 
 * @param   x_pos
 *          Position on the axis X of the line.
 * @param   y_pos
 *          Position on the axis Y of the line.
 * @param   x_length
 *          Set the initial length of the rectangle on the X axis.
 * @param   y_length
 *          Set the initial length of the rectangle on the X axis.
 * @param   color
 *          Color of the perimeter of the rectangle and the filled. (BLACK or WHITE)
 * @param   filled
 *          Boolean varible that creates a filled rectangle or not.
 * */

rectangle::rectangle(uint16_t x_pos, uint16_t y_pos, uint16_t x_length, uint16_t y_length, uint8_t color, bool filled){
    this->x_pos=x_pos;
    this->y_pos=y_pos;
    this->x_length=x_length;
    this->y_length=y_length;
    this->color=color;
    this->filled=filled;
}

rectangle::~rectangle(){

}

/**
 * @brief This function generates the rectangle figure. Depends of the filled and color option, it will create a perimeter of points with
 * the dimensions required or it will created an area points with the required dimensions.
 * 
 * @param   frame 
 *          Frame class previously initialize.
 * */

void rectangle::save_figure(epdframe &frame){
    if(!this->filled){
        //Print the horizontal points of the rectangle.
        for (int i = this->x_pos; i < this->x_pos + this->x_length; i++) {
            if(this->color==BLACK){
                frame.frame_buffer[(i + this->y_pos * frame.scr_width) / 8] &= ~(0x80 >> (i % 8)); 
                // Just apply the offset of the Y axis.
                frame.frame_buffer[(i + (this->y_pos + this->y_length) * frame.scr_width) / 8] &= ~(0x80 >> (i % 8));
            }
            else{
                frame.frame_buffer[(i + this->y_pos * frame.scr_width) / 8] |= 0x80 >> (i % 8);
                frame.frame_buffer[(i + (this->y_pos + this->y_length) * frame.scr_width) / 8] |= 0x80 >> (i % 8);
            }
        }
        //Print the vertical points of the rectangle
        for (int i = this->y_pos; i < this->y_pos + this->y_length; i++) {
            if(this->color==BLACK){
                frame.frame_buffer[(this->x_pos + i * frame.scr_width) / 8] &= ~(0x80 >> (this->x_pos % 8)); 
                frame.frame_buffer[((this->x_pos + this->x_length) + i * frame.scr_width) / 8] &= ~(0x80 >> ((this->x_pos + this->x_length) % 8));
            }
            else{
                frame.frame_buffer[(this->x_pos + i * frame.scr_width) / 8]  |= 0x80 >> (this->x_pos % 8);
                frame.frame_buffer[((this->x_pos + this->x_length) + i * frame.scr_width) / 8] |= 0x80 >> ((this->x_pos + this->x_length) % 8);
            } 
        }
    }
    else{
        for (int x = this->x_pos; x < (this->x_pos + this->x_length); x++) {
            for (int y = this->y_pos; y < (this->y_pos + this->y_length); y++) {
                if(this->color==BLACK){
                    frame.frame_buffer[(x + y * frame.scr_width) / 8] &= ~(0x80 >> (x % 8));
                }
                else{
                    frame.frame_buffer[(x + y * frame.scr_width) / 8] |= 0x80 >> (x % 8);
                }
            }
        }

    }
}

/**
 * @brief This function deletes from the buffer the figure, by changing the color of the figure to the opposite.
 * 
 * @param   frame 
 *          Frame class previously initialize.
 * */

void rectangle::delete_figure(epdframe &frame){
    this->color=!this->color; // We change the color to the opposite
    this->save_figure(frame); // Repaint the figure on the opposite color.
    this->color=!this->color; // Set to the original color, if we want to repaint on the future.
}


/**
 * @brief Return the X position of the figure.
 * 
 * @return Return an unsigned integer with the X position.
 * */

uint16_t rectangle::get_x_pos(){
    return this->x_pos;
}

/**
 * @brief Return the Y position of the figure.
 * 
 * @return Return an unsigned integer with the Y position.
 * */

uint16_t rectangle::get_y_pos(){
    return this->y_pos;
}

/**
 * @brief Return the length of the rectangle on the X axis.
 * 
 * @return Return an unsigned integer with the length of the rectangle on the X axis.
 * */

uint16_t rectangle::get_x_length(){
    return this->x_length;
}

/**
 * @brief Return the length of the rectangle on the Y axis.
 * 
 * @return Return an unsigned integer with the length of the rectangle on the Y axis.
 * */

uint16_t rectangle::get_y_length(){
    return this->y_length;
}

/**
 * @brief Return the color of the figure.
 * 
 * @return 1 is white and 0 is black.
 * */

uint8_t rectangle::get_color(){
    return this->color;
}

/**
 * @brief Return if the figure is filled
 * 
 * @return true -> rectangle filled, otherwise false.
 * */

bool rectangle::get_filled(){
    return this->filled;
}

/**********************Set functions*************************/

/**
 * @brief Set the X position of the figure.
 * 
 * @param   x_pos
 *          X position of the rectangle (Left superior axis is origin of coordinates)
 * */

void rectangle::set_x_pos(uint16_t x_pos){
    this->x_pos=x_pos;
}

/**
 * @brief Set the Y position of the figure.
 * 
 * @param   y_pos
 *          Y position of the rectangle (Left superior axis is origin of coordinates)
 * */

void rectangle::set_y_pos(uint16_t y_pos){
    this->y_pos=y_pos;
}

/**
 * @brief Set the length of the rectangle on the X axis.
 * 
 * @param   x_length
 *          Set the lenght of the X axis of the rectangle from the origin of the coordinates.
 * */

void rectangle::set_x_length(uint16_t x_lenght){
    this->x_length=x_length;
}

/**
 * @brief Set the length of the rectangle on the Y axis.
 * 
 * @param   y_length
 *          Set the lenght of the Y axis of the rectangle from the origin of the coordinates.
 * */

void rectangle::set_y_length(uint16_t y_length){
    this->y_length=y_length;
}

/**
 * @brief Set the color of the figure
 * 
 * @param   color
 *          Color of the figure, it can be BLACK or WHITE. If the figure is not filled,
 *          ony the outside line, will has the desired color.
 * */

void rectangle::set_color(uint8_t color){
    this->color=color;
}

/**
 * @brief Set filled the figure.
 * 
 * @param   filled
 *          Boolean variable to fill (true) or not the figure.
 * */

void rectangle::set_filled(bool filled){
    this->filled=filled;
}