#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *src;
extern ptrdiff_t linesize;
extern int w;
extern int h;
extern float *histogram;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every second element first, then the others (interleaved stride pattern)
    for (y = 0; y < h; y++) {
        uint16_t *row = src + y * linesize;
        // Process even indices
        for (x = 0; x < w; x += 2) {
            histogram[row[x]] += 1;
        }
        // Process odd indices
        for (x = 1; x < w; x += 2) {
            histogram[row[x]] += 1;
        }
    }
}
