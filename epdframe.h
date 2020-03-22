#include <stdint.h>
#include <math.h>
#include <Arduino.h>
#include <stdio.h>

#include "epd4in2.h"
#include "images/image_index.h"
#include "fonts/fonts_index.h"

#if (defined(__AVR__))
#include <avr\pgmspace.h>
#else
#include <pgmspace.h>
#endif

#define BLACK 0
#define WHITE 1

/**
 * @brief Class that store the data of the frame and perform the send operations .
 **/

class epdframe{
    public:
        epdframe(uint8_t background_color, uint16_t scr_widht, uint16_t scr_height);
        ~epdframe();
        uint8_t init_screen();
        void show();
        void clear_screen();
        void wipe_buffer();
        friend class line;
        friend class circle;
        friend class rectangle;
        friend class image;
        friend class text_box;
        
    private:

        uint16_t scr_width; // Number of pixels on the Y axis.
        uint16_t scr_height; // Number of pixels on the X axis.
        uint8_t background_color; // Background color of the screen (Black or white)
        uint32_t buffer_size; // TODO: Implement dinamic buffer calculation.
        PROGMEM unsigned char frame_buffer[16000]; // Buffer to save the figures.
        Epd epd; // Epaper class object to control the screen.
};

/**
 * @brief Class to store the data of the line figure.
 * */

class line{
    public:
        line(uint16_t x_pos, uint16_t y_pos, uint16_t degree, uint16_t line_widht, uint16_t color);
        ~line();
        void save_figure(epdframe &frame);
        void delete_figure(epdframe &frame);
        uint16_t get_x_pos();
        uint16_t get_y_pos();
        uint16_t get_degree();
        uint16_t get_line_width();
        uint8_t get_color();
        void change_x_pos(uint16_t x_pos);
        void change_y_pos(uint16_t y_pos);
        void change_degree(uint16_t degree);
        void change_color(uint8_t color);
        void change_line_width(uint16_t line_width);

    private:
        uint16_t x_pos; 
        uint16_t y_pos;
        uint16_t degree;
        uint16_t line_width;
        uint8_t color;
};

/**
 * @brief Class to store the data of the circle figure.
 * */

class circle{
    public:
        circle(uint16_t x_pos, uint16_t y_pos, uint16_t circle_radius, uint8_t color, bool filled);
        ~circle();
        void save_figure(epdframe &frame);
        void delete_figure(epdframe &frame);
        uint16_t get_x_pos();
        uint16_t get_y_pos();
        uint16_t get_radius();
        bool get_filled();
        uint8_t get_color();
        void change_x_pos(uint16_t x_pos);
        void change_y_pos(uint16_t y_pos);
        void change_radius(uint16_t degree);
        void change_color(uint8_t color);
        void change_filled(bool filled);

    private:
        uint16_t x_pos; 
        uint16_t y_pos;
        uint16_t radius;
        uint8_t color;
        bool filled;
};

/**
 * @brief Class to store the data of the rectangule figure.
 * */

class rectangle{
    public:
        rectangle(uint16_t x_pos, uint16_t y_pos, uint16_t x_length, uint16_t y_length, uint8_t color, bool filled);
        ~rectangle();
        void save_figure(epdframe &frame);
        void delete_figure(epdframe &frame);
        uint16_t get_x_pos();
        uint16_t get_y_pos();
        uint16_t get_x_length();
        uint16_t get_y_length();
        uint8_t get_color();
        bool get_filled();
        void set_x_pos(uint16_t x_pos);
        void set_y_pos(uint16_t y_pos);
        void set_x_length(uint16_t x_length);
        void set_y_length(uint16_t y_length);
        void set_color(uint8_t color);
        void set_filled(bool filled);
    private:
        uint16_t x_pos;
        uint16_t y_pos;
        uint16_t x_length;
        uint16_t y_length;
        uint8_t color;
        bool filled;
};

/**
 * @brief Class to store the data of a image
 * */

class image{
    public:
        image(uint16_t x_pos, uint16_t y_pos, const unsigned char *image_buffer, uint16_t img_width, uint16_t image_heigth);
        ~image();
        void save_image(epdframe &frame);
        void delete_image(epdframe &frame);
        uint16_t get_x_pos();
        uint16_t get_y_pos();
        uint16_t get_image_width();
        uint16_t get_image_heigth();
        void set_x_pos(uint16_t x_pos);
        void set_y_pos(uint16_t y_pos);

    private:
        uint16_t x_pos;
        uint16_t y_pos;
        uint16_t image_width;
        uint16_t image_heigth;
        const unsigned char *image_buffer;
};

class text_box{
    public:
        text_box(uint16_t x_pos, uint16_t y_pos, sFONT* font, uint8_t color);
        ~text_box();
        void save_text(const char *text,epdframe &frame);
        void delete_text(epdframe &frame);
        void apply_change(epdframe &frame);
        uint16_t get_x_pos();
        uint16_t get_y_pos();
        //uint8_t get_text_font();
        //uint8_t get_font_size();
        uint8_t get_color();
        void set_x_pos(uint16_t x_pos);
        void set_y_pos(uint16_t y_pos);
        void set_font(sFONT* font, epdframe &frame);
        void set_color(uint8_t color);
    private:
        //void select_font();
        uint16_t x_pos;
        uint16_t y_pos;
        uint64_t buffer_size;
        //uint8_t text_font;
        //uint8_t font_size;
        uint8_t color;
        const char *text;
        sFONT* font;
};