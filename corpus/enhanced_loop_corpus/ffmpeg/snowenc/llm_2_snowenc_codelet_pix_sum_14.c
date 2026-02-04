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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2
    uint8_t *p = pix;
    int total_elements = h * w;
    int k;
    for (k = 0; k < total_elements; k += 2) {
        s += p[0];
        if (k + 1 < total_elements) {
            s += p[1];
        }
        p += 1;
    }
}
