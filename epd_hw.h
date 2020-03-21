#include <stdint.h>
#include <Arduino.h>


void dev_init();
void send_command(unsigned char command);
void send_data(unsigned char data);
void reset();
uint8_t dev_busy();