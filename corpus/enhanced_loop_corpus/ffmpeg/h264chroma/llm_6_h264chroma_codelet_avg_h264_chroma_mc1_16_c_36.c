#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t s = stride;
    int i_local = 0;
    uint16_t *dst_local = dst;
    uint16_t *src_local = src;
    int h_local = h;
    for (i = 0; i < h_local; i++) {
        int temp_val = (A * src_local[0] + B * src_local[1] + C * src_local[s + 0] + D * src_local[s + 1]);
        dst_local[0] = (((dst_local[0]) + (((temp_val + 32) >> 6) + 1) >> 1));
        dst_local += s;
        src_local += s;
        i_local++;
    }
    i = i_local;
}
