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
        if (entry < 255) {
            px[0] = plte[entry].red;
            px[1] = plte[entry].green;
            px[2] = plte[entry].blue;
            px[3] = plte[entry].alpha;
        } else {
            px[0] = px[1] = px[2] = 0;
            px[3] = 255;
        }
    }
}
