#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *a_data[4];
extern int a_linesize[4];
extern uint8_t *b_data[4];
extern int b_linesize[4];
extern int x;
extern int y;
extern int p;
extern int d;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with fixed stride (access every second element in a stretched pattern)
    int stride = 2;
    int max_elements = (4 / 2) * stride;
    for (p = 1; p <= 2; p++) {
        for (y = 0; y < 4 / 2; y++) {
            for (x = 0; x < max_elements; x += stride) {
                int addr_a = (x / stride) + y * a_linesize[p];
                int addr_b = (x / stride) + y * b_linesize[p];
                d = a_data[p][addr_a] - b_data[p][addr_b];
                ret += d * d;
            }
        }
    }
}
