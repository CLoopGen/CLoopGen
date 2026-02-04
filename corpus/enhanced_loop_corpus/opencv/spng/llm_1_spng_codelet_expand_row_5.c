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
    uint32_t chunk_size = 4;
    uint32_t outer_end = (width + chunk_size - 1) / chunk_size;
    for (uint32_t oi = 0; oi < outer_end; oi++) {
        for (uint32_t ii = 0; ii < chunk_size; ii++) {
            i = oi * chunk_size + ii;
            if (i >= width) break;
            px = row + i * 3;
            entry = scanline[i];
            px[0] = plte[entry].red;
            px[1] = plte[entry].green;
            px[2] = plte[entry].blue;
        }
    }
}
