#include "epdframe.h"

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

void line::save_figure(epdframe &frame){
    //TODO: Add different color
    int x1=0;
    int x2=0;
    int y1=0;
    int y2=0;

    /*Calculus the final */
    
    if(this->degree==0 || this->degree== 180){
        //Vertical Line
        if(this->degree==0){
            y1=this->y_pos;
            y2=this->y_pos - this->line_width;
            if(y2<0)y2=0;
            x1=this->x_pos;
            x2=this->x_pos;
        }
        else{
            y1=this->y_pos;
            y2=this->y_pos + this->line_width;
            x1=this->x_pos;
            x2=this->x_pos;
        }
    }
    else if(this->degree==90 || this->degree== 270){
        //Horizontal line
        if(this->degree==90){
            x1=this->x_pos;
            x2=this->x_pos + this->line_width;
            y1=this->y_pos;
            y2=this->y_pos;
        }
        else{
            x1=this->x_pos;
            x2=this->x_pos - this->line_width;
            if(x2<0)x2=0;
            y1=this->y_pos;
            y2=this->y_pos;
        }
    }
    else{
        //Line with different degree
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
    /*BRESENHAAM ALGORITHM FOR LINE DRAWING*/

    int x,y,dx,dy,dx1,dy1,px,py,xe,ye,i;
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
        frame.frame_buffer[(x + y * frame.scr_width) / 8] &= ~(0x80 >> (x % 8));

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

uint16_t line::get_x_pos(){
    return this->x_pos;
}

uint16_t line::get_y_pos(){
    return this->y_pos;
}
uint16_t line::get_degree(){
    return this->degree;
}
uint16_t line::get_line_width(){
    return this->line_width;
}
uint8_t line::get_color(){
    return this->color;
}
void line::change_x_pos(uint16_t x_pos){
    this->x_pos=x_pos;
}
void line::change_y_pos(uint16_t y_pos){
    this->y_pos=y_pos;
}
void line::change_degree(uint16_t degree){
    this->degree=degree;
}  
void line::change_color(uint8_t color){
    this->color=color;
}

void line::change_line_width(uint16_t line_width){
    this->line_width=line_width;
}