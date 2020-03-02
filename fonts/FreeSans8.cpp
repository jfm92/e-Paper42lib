#include "fonts_index.h"
#if defined(__AVR__) || defined(ARDUINO_ARCH_SAMD)
#include <avr/pgmspace.h>
#elif defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#endif

const uint8_t FreeSans8_table [] PROGMEM =
{
  //   32
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // ! 33
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x00,  // ........
  0x40,  // .#......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // " 34
  0xE0,  // ###.....
  0xE0,  // ###.....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // # 35
  0x10,  // ...#....
  0x50,  // .#.#....
  0xF0,  // ####....
  0x70,  // .###....
  0xF0,  // ####....
  0xE0,  // ###.....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // $ 36
  0x60,  // .##.....
  0xB0,  // #.##....
  0xE0,  // ###.....
  0x70,  // .###....
  0xB0,  // #.##....
  0xF0,  // ####....
  0x20,  // ..#.....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // % 37
  0x40,  // .#......
  0xA8,  // #.#.#...
  0xF0,  // ####....
  0x14,  // ...#.#..
  0x2A,  // ..#.#.#.
  0x2E,  // ..#.###.
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // & 38
  0x20,  // ..#.....
  0x50,  // .#.#....
  0x70,  // .###....
  0x68,  // .##.#...
  0x90,  // #..#....
  0x78,  // .####...
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // ' 39
  0x80,  // #.......
  0x80,  // #.......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // ( 40
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0xC0,  // ##......
  0xC0,  // ##......
  0x40,  // .#......
  0x40,  // .#......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // ) 41
  0x80,  // #.......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x80,  // #.......
  0x00,  // ........
  0x00,  // ........
  // * 42
  0x40,  // .#......
  0x60,  // .##.....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // + 43
  0x00,  // ........
  0x00,  // ........
  0x20,  // ..#.....
  0x20,  // ..#.....
  0xF0,  // ####....
  0x20,  // ..#.....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // , 44
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x40,  // .#......
  0x40,  // .#......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // - 45
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0xC0,  // ##......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // . 46
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x40,  // .#......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // / 47
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x00,  // ........
  0x80,  // #.......
  0x80,  // #.......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // 0 48
  0x60,  // .##.....
  0xD0,  // ##.#....
  0x90,  // #..#....
  0x90,  // #..#....
  0x90,  // #..#....
  0x70,  // .###....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // 1 49
  0x20,  // ..#.....
  0x60,  // .##.....
  0x20,  // ..#.....
  0x20,  // ..#.....
  0x20,  // ..#.....
  0x20,  // ..#.....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // 2 50
  0x60,  // .##.....
  0xD0,  // ##.#....
  0x10,  // ...#....
  0x20,  // ..#.....
  0x40,  // .#......
  0xF0,  // ####....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // 3 51
  0x60,  // .##.....
  0xD0,  // ##.#....
  0x30,  // ..##....
  0x30,  // ..##....
  0x90,  // #..#....
  0xF0,  // ####....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // 4 52
  0x20,  // ..#.....
  0x30,  // ..##....
  0x70,  // .###....
  0xB0,  // #.##....
  0xF0,  // ####....
  0x30,  // ..##....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // 5 53
  0x70,  // .###....
  0xC0,  // ##......
  0xF0,  // ####....
  0x10,  // ...#....
  0x90,  // #..#....
  0xF0,  // ####....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // 6 54
  0x60,  // .##.....
  0xD0,  // ##.#....
  0xE0,  // ###.....
  0xD0,  // ##.#....
  0x90,  // #..#....
  0x70,  // .###....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // 7 55
  0xF0,  // ####....
  0x10,  // ...#....
  0x20,  // ..#.....
  0x20,  // ..#.....
  0x60,  // .##.....
  0x40,  // .#......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // 8 56
  0x60,  // .##.....
  0xD0,  // ##.#....
  0x70,  // .###....
  0xF0,  // ####....
  0x90,  // #..#....
  0xF0,  // ####....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // 9 57
  0x60,  // .##.....
  0xD0,  // ##.#....
  0x90,  // #..#....
  0x70,  // .###....
  0x10,  // ...#....
  0x70,  // .###....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // : 58
  0x00,  // ........
  0x00,  // ........
  0x40,  // .#......
  0x00,  // ........
  0x00,  // ........
  0x40,  // .#......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // ; 59
  0x00,  // ........
  0x00,  // ........
  0x40,  // .#......
  0x00,  // ........
  0x00,  // ........
  0x40,  // .#......
  0x40,  // .#......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // < 60
  0x00,  // ........
  0x00,  // ........
  0x10,  // ...#....
  0x60,  // .##.....
  0xE0,  // ###.....
  0x30,  // ..##....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // = 61
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0xF0,  // ####....
  0xF0,  // ####....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // > 62
  0x00,  // ........
  0x00,  // ........
  0xC0,  // ##......
  0x70,  // .###....
  0x30,  // ..##....
  0xC0,  // ##......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // ? 63
  0x70,  // .###....
  0xD0,  // ##.#....
  0x10,  // ...#....
  0x20,  // ..#.....
  0x20,  // ..#.....
  0x20,  // ..#.....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // @ 64
  0x3C,  // ..####..
  0x42,  // .#....#.
  0xDF,  // ##.#####
  0xAD,  // #.#.##.#
  0xAE,  // #.#.###.
  0x54,  // .#.#.#..
  0x3C,  // ..####..
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // A 65
  0x30,  // ..##....
  0x70,  // .###....
  0x50,  // .#.#....
  0x78,  // .####...
  0xD8,  // ##.##...
  0x88,  // #...#...
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // B 66
  0xF0,  // ####....
  0xC8,  // ##..#...
  0xF8,  // #####...
  0xF8,  // #####...
  0xC8,  // ##..#...
  0xF8,  // #####...
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // C 67
  0x78,  // .####...
  0x48,  // .#..#...
  0x80,  // #.......
  0x80,  // #.......
  0xC8,  // ##..#...
  0x78,  // .####...
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // D 68
  0x70,  // .###....
  0xC8,  // ##..#...
  0xCC,  // ##..##..
  0xCC,  // ##..##..
  0xC8,  // ##..#...
  0xF8,  // #####...
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // E 69
  0x78,  // .####...
  0xC0,  // ##......
  0xF0,  // ####....
  0xF0,  // ####....
  0xC0,  // ##......
  0xF8,  // #####...
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // F 70
  0x78,  // .####...
  0xC0,  // ##......
  0xF0,  // ####....
  0xF0,  // ####....
  0xC0,  // ##......
  0xC0,  // ##......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // G 71
  0x78,  // .####...
  0x4C,  // .#..##..
  0x80,  // #.......
  0x9C,  // #..###..
  0xC4,  // ##...#..
  0x7C,  // .#####..
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // H 72
  0xC8,  // ##..#...
  0xC8,  // ##..#...
  0xF8,  // #####...
  0xF8,  // #####...
  0xC8,  // ##..#...
  0xC8,  // ##..#...
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // I 73
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // J 74
  0x30,  // ..##....
  0x30,  // ..##....
  0x30,  // ..##....
  0x30,  // ..##....
  0xB0,  // #.##....
  0xE0,  // ###.....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // K 75
  0xC8,  // ##..#...
  0xD0,  // ##.#....
  0xE0,  // ###.....
  0xF0,  // ####....
  0xD0,  // ##.#....
  0xC8,  // ##..#...
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // L 76
  0xC0,  // ##......
  0xC0,  // ##......
  0xC0,  // ##......
  0xC0,  // ##......
  0xC0,  // ##......
  0xF0,  // ####....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // M 77
  0xC4,  // ##...#..
  0xCC,  // ##..##..
  0xEC,  // ###.##..
  0xEC,  // ###.##..
  0xFC,  // ######..
  0xD4,  // ##.#.#..
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // N 78
  0xC8,  // ##..#...
  0xE8,  // ###.#...
  0xE8,  // ###.#...
  0xF8,  // #####...
  0xD8,  // ##.##...
  0xC8,  // ##..#...
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // O 79
  0x78,  // .####...
  0xCC,  // ##..##..
  0x84,  // #....#..
  0x84,  // #....#..
  0xC4,  // ##...#..
  0x78,  // .####...
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // P 80
  0x78,  // .####...
  0xC8,  // ##..#...
  0xD8,  // ##.##...
  0xF0,  // ####....
  0xC0,  // ##......
  0xC0,  // ##......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // Q 81
  0x78,  // .####...
  0xCC,  // ##..##..
  0x84,  // #....#..
  0x84,  // #....#..
  0xCC,  // ##..##..
  0x7C,  // .#####..
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // R 82
  0x78,  // .####...
  0xC8,  // ##..#...
  0xC8,  // ##..#...
  0xF8,  // #####...
  0xC8,  // ##..#...
  0xC8,  // ##..#...
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // S 83
  0x70,  // .###....
  0xC8,  // ##..#...
  0x60,  // .##.....
  0x38,  // ..###...
  0x88,  // #...#...
  0x78,  // .####...
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // T 84
  0xF8,  // #####...
  0x20,  // ..#.....
  0x20,  // ..#.....
  0x20,  // ..#.....
  0x20,  // ..#.....
  0x20,  // ..#.....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // U 85
  0xC8,  // ##..#...
  0xC8,  // ##..#...
  0xC8,  // ##..#...
  0xC8,  // ##..#...
  0xC8,  // ##..#...
  0x78,  // .####...
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // V 86
  0x88,  // #...#...
  0xC8,  // ##..#...
  0x58,  // .#.##...
  0x50,  // .#.#....
  0x30,  // ..##....
  0x30,  // ..##....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // W 87
  0x9B,  // #..##.##
  0xDA,  // ##.##.#.
  0x5A,  // .#.##.#.
  0x6E,  // .##.###.
  0x6E,  // .##.###.
  0x64,  // .##..#..
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // X 88
  0xC8,  // ##..#...
  0x50,  // .#.#....
  0x30,  // ..##....
  0x30,  // ..##....
  0x50,  // .#.#....
  0xC8,  // ##..#...
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // Y 89
  0x88,  // #...#...
  0x58,  // .#.##...
  0x70,  // .###....
  0x30,  // ..##....
  0x20,  // ..#.....
  0x20,  // ..#.....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // Z 90
  0xF8,  // #####...
  0x10,  // ...#....
  0x30,  // ..##....
  0x60,  // .##.....
  0x40,  // .#......
  0xF8,  // #####...
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // [ 91
  0xC0,  // ##......
  0x80,  // #.......
  0x80,  // #.......
  0x80,  // #.......
  0x80,  // #.......
  0x80,  // #.......
  0x80,  // #.......
  0xC0,  // ##......
  0x00,  // ........
  0x00,  // ........
  // \ 92
  0x80,  // #.......
  0x80,  // #.......
  0x80,  // #.......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // ] 93
  0xC0,  // ##......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0xC0,  // ##......
  0x00,  // ........
  0x00,  // ........
  // ^ 94
  0x40,  // .#......
  0x60,  // .##.....
  0xE0,  // ###.....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // _ 95
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0xF0,  // ####....
  0x00,  // ........
  0x00,  // ........
  // ` 96
  0xC0,  // ##......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // a 97
  0x00,  // ........
  0x00,  // ........
  0x70,  // .###....
  0x70,  // .###....
  0xD0,  // ##.#....
  0xF0,  // ####....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // b 98
  0x80,  // #.......
  0xA0,  // #.#.....
  0xF0,  // ####....
  0x90,  // #..#....
  0x90,  // #..#....
  0xF0,  // ####....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // c 99
  0x00,  // ........
  0x00,  // ........
  0xF0,  // ####....
  0x80,  // #.......
  0x90,  // #..#....
  0xF0,  // ####....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // d 100
  0x10,  // ...#....
  0x10,  // ...#....
  0xF0,  // ####....
  0x90,  // #..#....
  0x90,  // #..#....
  0xF0,  // ####....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // e 101
  0x00,  // ........
  0x00,  // ........
  0x70,  // .###....
  0xF0,  // ####....
  0x90,  // #..#....
  0x70,  // .###....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // f 102
  0x40,  // .#......
  0xC0,  // ##......
  0xC0,  // ##......
  0xC0,  // ##......
  0xC0,  // ##......
  0xC0,  // ##......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // g 103
  0x00,  // ........
  0x00,  // ........
  0xF0,  // ####....
  0x90,  // #..#....
  0x90,  // #..#....
  0xF0,  // ####....
  0x90,  // #..#....
  0x60,  // .##.....
  0x00,  // ........
  0x00,  // ........
  // h 104
  0x80,  // #.......
  0xC0,  // ##......
  0xF0,  // ####....
  0xD0,  // ##.#....
  0x90,  // #..#....
  0x90,  // #..#....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // i 105
  0x80,  // #.......
  0x00,  // ........
  0x80,  // #.......
  0x80,  // #.......
  0x80,  // #.......
  0x80,  // #.......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // j 106
  0x80,  // #.......
  0x00,  // ........
  0x80,  // #.......
  0x80,  // #.......
  0x80,  // #.......
  0x80,  // #.......
  0x80,  // #.......
  0x80,  // #.......
  0x00,  // ........
  0x00,  // ........
  // k 107
  0x80,  // #.......
  0x80,  // #.......
  0xA0,  // #.#.....
  0xE0,  // ###.....
  0xA0,  // #.#.....
  0x90,  // #..#....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // l 108
  0x80,  // #.......
  0x80,  // #.......
  0x80,  // #.......
  0x80,  // #.......
  0x80,  // #.......
  0x80,  // #.......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // m 109
  0x00,  // ........
  0x20,  // ..#.....
  0xFC,  // ######..
  0xD4,  // ##.#.#..
  0x94,  // #..#.#..
  0x94,  // #..#.#..
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // n 110
  0x00,  // ........
  0x00,  // ........
  0xF0,  // ####....
  0xD0,  // ##.#....
  0x90,  // #..#....
  0x90,  // #..#....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // o 111
  0x00,  // ........
  0x00,  // ........
  0xF0,  // ####....
  0x90,  // #..#....
  0x90,  // #..#....
  0x70,  // .###....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // p 112
  0x00,  // ........
  0x20,  // ..#.....
  0xF0,  // ####....
  0x90,  // #..#....
  0xD0,  // ##.#....
  0xF0,  // ####....
  0x80,  // #.......
  0x80,  // #.......
  0x00,  // ........
  0x00,  // ........
  // q 113
  0x00,  // ........
  0x00,  // ........
  0xF0,  // ####....
  0x90,  // #..#....
  0x90,  // #..#....
  0xF0,  // ####....
  0x10,  // ...#....
  0x10,  // ...#....
  0x00,  // ........
  0x00,  // ........
  // r 114
  0x00,  // ........
  0x00,  // ........
  0xE0,  // ###.....
  0xC0,  // ##......
  0x80,  // #.......
  0x80,  // #.......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // s 115
  0x00,  // ........
  0x00,  // ........
  0xF0,  // ####....
  0xE0,  // ###.....
  0x30,  // ..##....
  0xF0,  // ####....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // t 116
  0x00,  // ........
  0xC0,  // ##......
  0xC0,  // ##......
  0xC0,  // ##......
  0xC0,  // ##......
  0xC0,  // ##......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // u 117
  0x00,  // ........
  0x00,  // ........
  0x90,  // #..#....
  0x90,  // #..#....
  0x90,  // #..#....
  0xF0,  // ####....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // v 118
  0x00,  // ........
  0x00,  // ........
  0x90,  // #..#....
  0xE0,  // ###.....
  0x60,  // .##.....
  0x60,  // .##.....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // w 119
  0x00,  // ........
  0x00,  // ........
  0xBC,  // #.####..
  0xB8,  // #.###...
  0x78,  // .####...
  0x58,  // .#.##...
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // x 120
  0x00,  // ........
  0x00,  // ........
  0xF0,  // ####....
  0x60,  // .##.....
  0x60,  // .##.....
  0xB0,  // #.##....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // y 121
  0x00,  // ........
  0x00,  // ........
  0x90,  // #..#....
  0xE0,  // ###.....
  0x60,  // .##.....
  0x60,  // .##.....
  0x40,  // .#......
  0xC0,  // ##......
  0x00,  // ........
  0x00,  // ........
  // z 122
  0x00,  // ........
  0x00,  // ........
  0x70,  // .###....
  0x20,  // ..#.....
  0x40,  // .#......
  0xF0,  // ####....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // { 123
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0xC0,  // ##......
  0xC0,  // ##......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x00,  // ........
  0x00,  // ........
  // | 124
  0x00,  // ........
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  // } 125
  0x80,  // #.......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x40,  // .#......
  0x80,  // #.......
  0x00,  // ........
  0x00,  // ........
  // ~ 126
  0x00,  // ........
  0x00,  // ........
  0x40,  // .#......
  0x30,  // ..##....
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
  0x00,  // ........
};

/* Based on font FreeSans.ttf */
sFONT FreeSans8 = {
	FreeSans8_table,
  8, /* Width */
  10, /* Height */
};
