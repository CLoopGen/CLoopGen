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
    uint16_t *local_dst = dst;
    uint16_t *local_src = src;
    int local_h = h;

    for (i = 0; i < local_h; i++) {
        uint16_t val0 = local_src[0];
        uint16_t val1 = local_src[1];
        uint16_t val2 = local_src[2];
        uint16_t val3 = local_src[3];
        uint16_t val4 = local_src[4];
        uint16_t val_s0 = local_src[s + 0];
        uint16_t val_s1 = local_src[s + 1];
        uint16_t val_s2 = local_src[s + 2];
        uint16_t val_s3 = local_src[s + 3];
        uint16_t val_s4 = local_src[s + 4];

        int accum0 = A * val0 + B * val1 + C * val_s0 + D * val_s1;
        int accum1 = A * val1 + B * val2 + C * val_s1 + D * val_s2;
        int accum2 = A * val2 + B * val3 + C * val_s2 + D * val_s3;
        int accum3 = A * val3 + B * val4 + C * val_s3 + D * val_s4;

        local_dst[0] = ((accum0 + 32) >> 6);
        local_dst[1] = ((accum1 + 32) >> 6);
        local_dst[2] = ((accum2 + 32) >> 6);
        local_dst[3] = ((accum3 + 32) >> 6);

        local_dst += s;
        local_src += s;
    }
}
