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
    uint32_t j;
    for (j = 0; j < width * 3; j += 3) {
        entry = scanline[j / 3];
        px = row + j;
        px[0] = plte[entry].red;
        px[1] = plte[entry].green;
        px[2] = plte[entry].blue;
    }
}
