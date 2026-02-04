#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern ptrdiff_t linesize;
extern int w;
extern int h;
extern float *histogram;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – process every 2nd element in two passes to create non-unit stride
    for (int y = 0; y < h; y++) {
        // First pass: even indices with stride 2
        for (int x = 0; x < w; x += 2) {
            histogram[src[x]] += 1;
        }
        // Second pass: odd indices, creating a strided access pattern
        for (int x = 1; x < w; x += 2) {
            histogram[src[x]] += 1;
        }
        src += linesize;
    }
}
