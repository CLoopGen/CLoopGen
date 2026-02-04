#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *block;
extern uint8_t * *data;
extern int top;
extern int left;
extern  int *stride;
extern int i;
extern int j;
extern int u;
extern int v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base pointers and using linear offsets
    uint8_t *data0_base = data[0] + top * stride[0] + left;
    uint8_t *data1_base = data[1] + top * stride[1] + left;
    uint8_t *data2_base = data[2] + top * stride[1] + left;
    int stride0 = stride[0];
    int stride1 = stride[1];

    for (i = 0; i < 2; i++) {
        uint8_t *p0 = data0_base + i * stride0;
        uint8_t *p1 = data1_base + i * stride1;
        uint8_t *p2 = data2_base + i * stride1;
        for (j = 0; j < 2; j++) {
            *block++ = p0[j];
            u += p1[j];
            v += p2[j];
        }
    }
}
