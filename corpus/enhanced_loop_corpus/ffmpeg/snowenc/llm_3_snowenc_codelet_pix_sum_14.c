#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix;
extern int line_size;
extern int w;
extern int h;
extern int s;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every second pixel, then the offset ones
    uint8_t *p = pix;
    int stride = 2;
    int i, j;

    // First pass: even-indexed pixels in row-major order
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j += stride) {
            s += p[j];
        }
        p += line_size;
    }

    p = pix + 1; // Reset pointer to start at second pixel

    // Second pass: odd-indexed pixels
    for (i = 0; i < h; i++) {
        for (j = 0; j < w - 1; j += stride) {
            s += p[j];
        }
        p += line_size;
    }
}
