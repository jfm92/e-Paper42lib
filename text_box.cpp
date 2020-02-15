#include "epdframe.h"

text_box::text_box(uint16_t x_pos, uint16_t y_pos, uint8_t text_font, uint8_t font_size, uint8_t font_color){
    this->x_pos=x_pos;
    this->y_pos=y_pos;
    this->text_font=text_font;
    this->font_size=font_size;
    this->color=color;
    this->select_font();//With type and font size we choose the required font.
}

text_box::~text_box(){

}

void text_box::save_text(const char* text, epdframe &frame){
    const char* p_text = text;
    this->text=text; // Save the text on the buffer for future use.
    uint32_t counter = 0; //Variable to save the number of characters of the string.
    int refcolumn = this->x_pos; //Reference column on the x axis which we will start to paint the characters.
    uint16_t y_pos_aux=this->y_pos; // This is an auxilary position to save the Y position of the text.

    //This loop will go over each character of the string painting each character on the screen buffer
    while (*p_text != 0) {
        if(*p_text=='\n'){
            //If we detect a newline character, we don't create a new character, we just move the coordinates of the X axis.
            y_pos_aux+=this->font->Height;
            refcolumn=this->x_pos;
        }
        else{
            //If is a "normal" character we will save on the screen buffer.
            int i, j;
            unsigned int char_offset = (*p_text - ' ') * this->font->Height * (this->font->Width / 8 + (this->font->Width % 8 ? 1 : 0));
            const unsigned char* ptr = &font->table[char_offset];
            for (j = 0; j < this->font->Height; j++) {
                for (i = 0; i < this->font->Width; i++) {
                    if (pgm_read_byte(ptr) & (0x80 >> (i % 8))) {
                        if(this->color==BLACK){
                            //Save a black character.
                            frame.frame_buffer[((refcolumn + i) + (y_pos_aux+j) * frame.scr_width) / 8] &= ~(0x80 >> ((refcolumn + i) % 8)); 
                        }
                        else{
                            //Save a white character.
                            frame.frame_buffer[((refcolumn + i) + (y_pos_aux+j) * frame.scr_width) / 8] |= 0x80 >> ((refcolumn + i) % 8);
                        }
                    }
                    if (i % 8 == 7) {
                        ptr++;
                    }
                }
                if (this->font->Width % 8 != 0) {
                    ptr++;
                }
            }
            //Next position on the buffer with the width of the letter. This depends on the font size.
            refcolumn += this->font->Width;
        }
        //Next character of the string and increment the number of character on the buffer.
        p_text++;
        counter++;
    }
}

void text_box::delete_text(epdframe &frame){
    if(this->color==BLACK){
        this->color=!this->color;
        this->save_text(this->text,frame);
        this->color=!this->color;
    }
}

void text_box::apply_change(epdframe &frame){
    this->save_text(this->text,frame);
}

uint16_t text_box::get_x_pos(){
    return this->x_pos;
}

uint16_t text_box::get_y_pos(){
    return this->y_pos;
}

uint8_t text_box::get_text_font(){
    return this->text_font;
}

uint8_t text_box::get_font_size(){
    return this->font_size;
}

uint8_t text_box::get_color(){
    return this->color;
}

void text_box::set_x_pos(uint16_t x_pos){
    this->x_pos=x_pos;
}

void text_box::set_y_pos(uint16_t y_pos){
    this->y_pos=y_pos;
}

void text_box::set_font(uint8_t text_font, uint8_t font_size, epdframe &frame){
    this->delete_text(frame);
    this->font_size=font_size;
    this->text_font=text_font;
    select_font();
}

void text_box::set_color(uint8_t color){
    this->color=color;
}

/**
 * Private functions
 * */

void text_box::select_font(){
    if(this->text_font==GENERIC){
        if(this->font_size==8){
            this->font=&Font8;
        }
        else if(this->font_size==12){
            this->font=&Font12;
        }
        else if(this->font_size==16){
            this->font=&Font16;
        }
        else if(this->font_size==24){
            this->font=&Font24;
        }
        else{
            printf("Error size not available-> 8,12,16,24 \r\n");
            printf("Setting by default size 8\r\n");
            this->font=&Font8;
            this->font_size=8;
        }
    }
    else{
        printf("Font not avilable\r\n");
        printf("Setting by defaul Generic size 8\r\n");
        this->font=&Font8;
        this->font_size=8;
        this->text_font=GENERIC;
    }

}

