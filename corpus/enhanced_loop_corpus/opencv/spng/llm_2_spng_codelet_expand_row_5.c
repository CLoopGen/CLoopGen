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
    // Variant 1: Consecutive memory access with pointer arithmetic and loop unrolling for improved spatial locality
    uint8_t *r = row;
    const uint8_t *s = scanline;
    size_t idx;

    for (i = 0; i + 3 < width; i += 4) {
        idx = s[i];
        r[0] = plte[idx].red;   r[1] = plte[idx].green;   r[2] = plte[idx].blue;
        idx = s[i+1];
        r[3] = plte[idx].red;   r[4] = plte[idx].green;   r[5] = plte[idx].blue;
        idx = s[i+2];
        r[6] = plte[idx].red;   r[7] = plte[idx].green;   r[8] = plte[idx].blue;
        idx = s[i+3];
        r[9] = plte[idx].red;   r[10] = plte[idx].green; r[11] = plte[idx].blue;
        r += 12;
    }

    // Handle remaining elements
    for (; i < width; i++) {
        px = row + i * 3;
        entry = scanline[i];
        px[0] = plte[entry].red;
        px[1] = plte[entry].green;
        px[2] = plte[entry].blue;
    }
}
