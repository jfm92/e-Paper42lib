#include <stdint.h>
#include "epd4in2.h"

#define BLACK 0
#define WHITE 1

class epdframe{
    public:
        epdframe(uint8_t background_color, uint16_t scr_widht, uint16_t scr_height);
        ~epdframe();
        void show();
        void clear_screen();
        void wipe_buffer();
        friend class line;

    private:

        void calculate_buffer_size();
        uint16_t scr_width;
        uint16_t scr_height;
        uint8_t background_color;
        uint32_t buffer_size;
        unsigned char frame_buffer[16000];
        Epd epd;
};

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
        uint16_t color;
};