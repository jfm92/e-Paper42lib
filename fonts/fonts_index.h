#define MAX_HEIGHT_FONT         24
#define MAX_WIDTH_FONT          17
#define OFFSET_BITMAP           54

#define GENERIC 0x01

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

struct sFONT {
  const uint8_t *table;
  uint16_t Width;
  uint16_t Height;
};

extern sFONT Font24;
extern sFONT Font20;
extern sFONT Font16;
extern sFONT Font12;
extern sFONT Font8;