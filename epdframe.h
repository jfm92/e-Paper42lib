#include <stdint.h>
#include "epd4in2.h"

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

    private:

        uint16_t scr_width; // Number of pixels on the Y axis.
        uint16_t scr_height; // Number of pixels on the X axis.
        uint8_t background_color; // Background color of the screen (Black or white)
        uint32_t buffer_size; // TODO: Implement dinamic buffer calculation.
        unsigned char frame_buffer[16000]; // Buffer to save the figures.
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