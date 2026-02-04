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



void loop() {
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling
    // We process two pixels at a time to promote consecutive memory writes and reduce indexing overhead.
    uint32_t i4 = (width / 2) * 2;  // Round down to even number
    unsigned char *px1, *px2;
    struct spng_plte_entry *entry1, *entry2;

    for (; i < i4; i += 2) {
        px1 = row + i * 4;
        px2 = row + (i + 1) * 4;

        entry1 = &plte[scanline[i]];
        entry2 = &plte[scanline[i + 1]];

        px1[0] = entry1->red;     px2[0] = entry2->red;
        px1[1] = entry1->green;   px2[1] = entry2->green;
        px1[2] = entry1->blue;    px2[2] = entry2->blue;
        px1[3] = entry1->alpha;   px2[3] = entry2->alpha;
    }

    // Handle remaining pixel if width is odd
    for (; i < width; i++) {
        px = row + i * 4;
        entry = scanline[i];
        px[0] = plte[entry].red;
        px[1] = plte[entry].green;
        px[2] = plte[entry].blue;
        px[3] = plte[entry].alpha;
    }
}
