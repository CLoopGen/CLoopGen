#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern int x;
extern int y;
extern int xy;
extern int yz;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < 7; y++) {
    for (int unroll_factor = 0; unroll_factor < 8; unroll_factor += 4) {
        int base_xy = y * stride + unroll_factor;
        int base_yz = y * 8 + unroll_factor;
        temp[base_yz] = src[base_xy - stride] + 2 * src[base_xy] + src[base_xy + stride];
        temp[base_yz + 1] = src[base_xy + 1 - stride] + 2 * src[base_xy + 1] + src[base_xy + 1 + stride];
        temp[base_yz + 2] = src[base_xy + 2 - stride] + 2 * src[base_xy + 2] + src[base_xy + 2 + stride];
        temp[base_yz + 3] = src[base_xy + 3 - stride] + 2 * src[base_xy + 3] + src[base_xy + 3 + stride];
    }
}
}
