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
    // Variant 2: Indirect access via lookup table for color components
    // Precompute base pointers to enable indirect component-wise access pattern.
    uint8_t *red_dst = row + 0;
    uint8_t *green_dst = row + 1;
    uint8_t *blue_dst = row + 2;
    uint8_t *alpha_dst = row + 3;
    const uint8_t *scan = scanline;

    // Step through indices and use indirect access by indexing into plte using scan[i]
    for (; i < width; i++) {
        struct spng_plte_entry *entry_ptr = &plte[scan[i]];
        red_dst[i * 4]   = entry_ptr->red;
        green_dst[i * 4] = entry_ptr->green;
        blue_dst[i * 4]  = entry_ptr->blue;
        alpha_dst[i * 4] = entry_ptr->alpha;
    }
}
