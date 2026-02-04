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
    for (j = 0; j < width; j++) {
        uint8_t entry_local = scanline[j];
        unsigned char *px_local = row + j * 3;
        px_local[0] = plte[entry_local].red;
        px_local[1] = plte[entry_local].green;
        px_local[2] = plte[entry_local].blue;
    }
}
