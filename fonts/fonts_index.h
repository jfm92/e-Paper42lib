#define MAX_HEIGHT_FONT         35
#define MAX_WIDTH_FONT          30
#define OFFSET_BITMAP           54

#define GENERIC 0x01

#define F

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

struct sFONT {
  const uint8_t *table;
  uint16_t Width;
  uint16_t Height;
};

// Generic fonts
extern sFONT Font24;
extern sFONT Font20;
extern sFONT Font16;
extern sFONT Font12;
extern sFONT Font8;

// FreeSans Bold
extern sFONT FreeSansBold58;
extern sFONT FreeSansBold50;

// FreeSans
extern sFONT FreeSans36;
extern sFONT FreeSans32;
extern sFONT FreeSans28;
extern sFONT FreeSans24;
extern sFONT FreeSans20;
extern sFONT FreeSans16;
extern sFONT FreeSans12;
extern sFONT FreeSans8;

// FreeMono
extern sFONT FreeMono42;
extern sFONT FreeMono40;
extern sFONT FreeMono36;
extern sFONT FreeMono32;
extern sFONT FreeMono28;
extern sFONT FreeMono24;
extern sFONT FreeMono20;
extern sFONT FreeMono16;
extern sFONT FreeMono12;
extern sFONT FreeMono8;
