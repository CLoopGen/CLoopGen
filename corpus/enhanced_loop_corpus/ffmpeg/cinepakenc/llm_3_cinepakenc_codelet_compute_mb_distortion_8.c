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
extern int d;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed loop order and stride simulation
    int idx;
    int stride_a = a_linesize[0];
    int stride_b = b_linesize[0];
    for (x = 0; x < 4; x++)
        for (y = 0; y < 4; y++) {
            idx = x + y * stride_a;
            d = a_data[0][idx] - b_data[0][x * stride_b + y]; // Transposed access pattern in b_data
            ret += d * d;
        }
}
