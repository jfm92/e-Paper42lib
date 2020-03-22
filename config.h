/**
 * Configuration file for the e-Paper lib for ESP32
 **/

/**
 * SPI bus configuration
 **/
#define RST_PIN     26
#define DC_PIN      27
#define CS_PIN      15
#define BUSY_PIN    25
#define MOSI_PIN    14
#define MISO_PIN    12 //Useless on this library but necessary to init the SPI
#define SCK_PIN     13
#define SPI_CLK  8000000 //1Mhz

/**
 * Screen configuration
 * Default config for 4.2 inch display
 **/

#define SCR_WIDTH   400
#define SCR_HEIGHT  300

/**
 * Fonts selection.
 * Uncheck the fonts that you want to use.
 * */

//#define GENERIC 
//#define FREESANS 
#define FREESANS_BOLD
//#define FREEMONO