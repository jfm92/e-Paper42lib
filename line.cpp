#include "epdframe.h"

/**
 * @brief Instantiates a new line class.
 * 
 * @param   x_pos
 *          Position on the axis X of the line.
 * @param   y_pos
 *          Position on the axis Y of the line.
 * @param   degree
 *          Degree that we want to set the line, relation with the initial point.
 * @param   line_width
 *          Width of the line.
 * @param   color
 *          Color of the line. It can be BLACK or WHITE.
 * */

line::line(uint16_t x_pos, uint16_t y_pos, uint16_t degree, uint16_t line_width, uint16_t color){
    this->x_pos=x_pos;
    this->y_pos=y_pos;
    this->degree=degree;
    this->line_width=line_width;
    this->color=color;
}

line::~line(){
    //delete_figure(epdframe &frame);
}

/**
 * @brief   This will generate the figure and it will save on the buffer.
 * 
 * @param   frame 
 *          Frame class previously initialize.
 * */
    
void line::save_figure(epdframe &frame){
    //TODO: Add different color
    int x1=0; // x initial point
    int x2=0; // x final point
    int y1=0; // y initial point
    int y2=0; // y final point

    int x,y,dx,dy,dx1,dy1,px,py,xe,ye,i; // Variables for bresenhaam algorithm

    // First we will calculate the final point of the figure base on degree set to the figure.
    if(this->degree==0 || this->degree== 180){
        //If the angle of the figure is 0 or 180, is a vertical line.
        if(this->degree==0){
            y1=this->y_pos; // Initial Y point
            y2=this->y_pos - this->line_width; //Final Y point
            x1=x2=this->x_pos;

            if(y2<0)y2=0; // If goes outside the screen limit, we wil set to 0
        }
        else{
            //The same as the other, but changing the orientation on the Y axis
            y1=this->y_pos;
            y2=this->y_pos + this->line_width;
            x1=this->x_pos;
            x2=this->x_pos;
        }
    }
    else if(this->degree==90 || this->degree== 270){
        //If the angle of the figure is 90 or 270, is a horizontal line.
        // We will perform the same calculus but on the different axis.
        if(this->degree==90){
            x1=this->x_pos;
            x2=this->x_pos + this->line_width;
            y1=y2=this->y_pos;

        }
        else{
            x1=this->x_pos;
            x2=this->x_pos - this->line_width;
            y1=y2=this->y_pos;

            if(x2<0)x2=0;
        }
    }
    else{
        // If the angle is different, we need to calculate the final position of the line appliying
        // basic trigonometrics functions.
        if(this->degree>0 && this->degree < 90){
            x1=this->x_pos;
            y1=this->y_pos;
            x2=this->line_width*sin((double)this->degree * PI / 180.0) + x1;
            y2=y1-(this->line_width*cos(this->degree * PI / 180.0));
        }
        else if(this->degree>90 && this->degree < 180){
            x1=this->x_pos;
            y1=this->y_pos;
            x2=this->line_width*cos((double)(this->degree-90) * PI / 180.0) + x1;
            y2=y1+(this->line_width*sin((this->degree-90) * PI / 180.0));
        }
        else if(this->degree>180 && this->degree < 270){
            x1=this->x_pos;
            y1=this->y_pos;
            x2=x1 - (this->line_width*sin((double)(this->degree-180) * PI / 180.0));
            y2=y1+(this->line_width*cos((this->degree-180) * PI / 180.0));
        }
        else{
            x1=this->x_pos;
            y1=this->y_pos;
            x2=x1 - (this->line_width*cos((double)(this->degree-270) * PI / 180.0));
            y2=y1 -(this->line_width*sin((this->degree-270) * PI / 180.0));
        }
    }
    // Once we've obtain the final point of the line, we need to apply the Bresenhaan to "draw" the line on the buffer 
    
    dx=x2-x1;
    dy=y2-y1;
    dx1=fabs(dx);
    dy1=fabs(dy);
    px=2*dy1-dx1;
    py=2*dx1-dy1;

    if(dy1<=dx1){
        if(dx>=0){
            x=x1;
            y=y1;
            xe=x2;
        }
        else{
            x=x2;
            y=y2;
            xe=x1;
        }
        frame.frame_buffer[(x + y * frame.scr_width) / 8] &= ~(0x80 >> (x % 8)); // Save to the buffer each point

        for(i=0;x<xe;i++){
            x=x+1;
            if(px<0){
                px=px+2*dy1;
            }
            else{
                if((dx<0 && dy<0) || (dx>0 && dy>0)){
                    y=y+1;
                }
                else{
                    y=y-1;
                }
                px=px+2*(dy1-dx1);
            }
            frame.frame_buffer[(x + y * frame.scr_width) / 8] &= ~(0x80 >> (x % 8));
        }
    }
    else{
        if(dy>=0){
            x=x1;
            y=y1;
            ye=y2;
        }
        else{
            x=x2;
            y=y2;
            ye=y1;
        }
        frame.frame_buffer[(x + y * frame.scr_width) / 8] &= ~(0x80 >> (x % 8));
        for(i=0;y<ye;i++){
            y=y+1;
            if(py<=0){
                py=py+2*dx1;
            }
            else{
                if((dx<0 && dy<0) || (dx>0 && dy>0)){
                    x=x+1;
                }
                else{
                    x=x-1;
                }
                py=py+2*(dx1-dy1);
            }
            frame.frame_buffer[(x + y * frame.scr_width) / 8] &= ~(0x80 >> (x % 8));
        }
    }

}

/** 
 * @brief This genererate the figure again on the opposite color to delete from the screen.
 * 
 * @param frame
 *        Pre initialize frame class where we want to delete the figure.
 * */

void line::delete_figure(epdframe &frame){
    // Change to the new 
    if(this->color == BLACK && frame.background_color == WHITE){
        for (int i = this->x_pos; i < this->x_pos + this->line_width; i++) {
            frame.frame_buffer[(i + this->y_pos * frame.scr_width) / 8] |= 0x80 >> (i % 8);
        }
    }
    else if(this->color == WHITE && frame.background_color == BLACK){
        for (int i = this->x_pos; i < this->x_pos + this->line_width; i++) {
            frame.frame_buffer[(i + this->y_pos * frame.scr_width) / 8] &= ~(0x80 >> (i % 8));
        }
    }
}

/**
 * @brief Return the X position of the figure.
 * 
 * @return Return an unsigned integer with the X position.
 * */

uint16_t line::get_x_pos(){
    return this->x_pos;
}

/**
 * @brief Return the Y position of the figure.
 * 
 * @return Return an unsigned integer with the Y position.
 * */

uint16_t line::get_y_pos(){
    return this->y_pos;
}

/**
 * @brief Return the angle on degrees of the figure.
 * 
 * @return Return an unsigned integer with the angle orientation of the figure.
 * */

uint16_t line::get_degree(){
    return this->degree;
}

/**
 * @brief Return the line width.
 * 
 * @return Return an unsigned integer with width of the line.
 * */

uint16_t line::get_line_width(){
    return this->line_width;
}

/**
 * @brief Return the color of the figure.
 * 
 * @return 1 is white and 0 is black.
 * */

uint8_t line::get_color(){
    return this->color;
}

/**
 * @brief Change the X position of the figure. Is necessary to re-save to see the changes.
 * 
 * @param   x_pos
 *          The new X position of the figure.
 * */

void line::change_x_pos(uint16_t x_pos){
    this->x_pos=x_pos;
}

/**
 * @brief Change the Y position of the figure. Is necessary to re-save to see the changes.
 * 
 * @param   x_pos
 *          The new Y position of the figure.
 * */

void line::change_y_pos(uint16_t y_pos){
    this->y_pos=y_pos;
}

/**
 * @brief Change the angle orientation of the figure. Is necessary to re-save to see the changes.
 * 
 * @param   degree
 *          The new angle orientation of the figure.
 * */

void line::change_degree(uint16_t degree){
    this->degree=degree;
}

/**
 * @brief Change the color of the figure. Is necessary to re-save to see the changes.
 * 
 * @param   color
 *          The new color of the figure. It can be BLACK/WHITE
 * */

void line::change_color(uint8_t color){
    this->color=color;
}

/**
 * @brief Change the line width of the figure. Is necessary to re-save to see the changes.
 * 
 * @param   line_width
 *          The new line_width of the figure.
 * */

void line::change_line_width(uint16_t line_width){
    this->line_width=line_width;
}