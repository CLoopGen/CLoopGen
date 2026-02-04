#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct spng_plte_entry {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
};


extern unsigned char *row;
extern  unsigned char *scanline;
extern uint32_t width;
extern uint32_t i;
extern unsigned char *px;
extern unsigned char entry;
extern  struct spng_plte_entry *plte;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < width; i++) {
        px = row + i * 4;
        entry = scanline[i];
        uint8_t red_val = plte[entry].red;
        uint8_t green_val = plte[entry].green;
        uint8_t blue_val = plte[entry].blue;
        uint8_t alpha_val = plte[entry].alpha;
        px[0] = red_val;
        px[1] = green_val;
        px[2] = blue_val;
        px[3] = alpha_val;
    }
}
