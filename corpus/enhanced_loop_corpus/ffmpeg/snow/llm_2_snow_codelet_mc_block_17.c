#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int b_w;
extern int b_h;
extern int dx;
extern int dy;
extern int x;
extern int y;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern  uint8_t *src3;
extern  uint8_t *src4;
extern int stride1;
extern int stride2;
extern int stride3;
extern int stride4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Prefetched Pointers
    // Instead of indexing into src1[x], src2[x], etc., we use local pointers that are incremented consecutively
    // to improve spatial locality and enable better compiler optimization.

    uint8_t *d = dst;
    uint8_t *s1 = src1;
    uint8_t *s2 = src2;
    uint8_t *s3 = src3;
    uint8_t *s4 = src4;

    for (int y = 0; y < b_h; y++) {
        uint8_t *d_ptr = d;
        uint8_t *s1_ptr = s1;
        uint8_t *s2_ptr = s2;
        uint8_t *s3_ptr = s3;
        uint8_t *s4_ptr = s4;

        for (int x = 0; x < b_w; x++) {
            d_ptr[x] = ((8 - dx) * (8 - dy) * s1_ptr[x] + 
                        dx * (8 - dy) * s2_ptr[x] + 
                        (8 - dx) * dy * s3_ptr[x] + 
                        dx * dy * s4_ptr[x] + 32) >> 6;
        }

        s1 += stride1;
        s2 += stride2;
        s3 += stride3;
        s4 += stride4;
        d += stride;
    }
}
