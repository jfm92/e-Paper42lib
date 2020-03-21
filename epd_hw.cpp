/**
 * @brief: This file contains the hardware logic to perform the SPI operations
 * */

#include <SPI.h>
#include "config.h"
#include "epd_hw.h"

#if (defined(__AVR__))
#include <avr\pgmspace.h>
#else
#include <pgmspace.h>
#endif

SPIClass * hspi = NULL;

void dev_init(){
    // Initialize a instance of the SPIClass
    // Using High Speed SPI bus of the ESP32
    hspi = new SPIClass(HSPI);
    hspi->begin(SCK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);

    pinMode(CS_PIN,OUTPUT);
    pinMode(RST_PIN,OUTPUT);
    pinMode(DC_PIN,OUTPUT);
    pinMode(BUSY_PIN,INPUT);

    digitalWrite(RST_PIN,HIGH);
}

void send_data(unsigned char command){
    hspi->beginTransaction(SPISettings(SPI_CLK, MSBFIRST, SPI_MODE0));
    
    digitalWrite(CS_PIN,LOW);
    digitalWrite(DC_PIN,HIGH);

    hspi->transfer(command);

    digitalWrite(CS_PIN,HIGH);
    hspi->endTransaction();
}

void send_command(unsigned char data){
    hspi->beginTransaction(SPISettings(SPI_CLK, MSBFIRST, SPI_MODE0));
    
    digitalWrite(CS_PIN,LOW);
    digitalWrite(DC_PIN,LOW);

    hspi->transfer(data);

    digitalWrite(CS_PIN,HIGH);
    hspi->endTransaction();
}

void reset(){
    digitalWrite(RST_PIN,LOW);
    delay(100);
    digitalWrite(RST_PIN,HIGH);
}

uint8_t dev_busy(){
    uint8_t dev_state = digitalRead(BUSY_PIN); 
    return dev_state;
}