#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t color;
extern int l;
extern int w;
extern  int linesize;
extern  uint32_t *py;
extern  uint32_t *pr;
extern  uint32_t *pb;
extern uint32_t *px;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with increased outer work — process every other row and double inner stride
    int skip = 2 * linesize;
    for (; py < pb; py += skip) {
        px = (uint32_t *)py + l;
        pr = px + w;
        // Process two elements per iteration, reducing inner loop iterations by ~half
        uint32_t *end = pr - 1;
        for (; px <= end; px += 2) {
            *px = color;
            *(px + 1) = color;
        }
        // Handle last element if width is odd
        if (px == pr - 1)
            *px = color;
    }
}
