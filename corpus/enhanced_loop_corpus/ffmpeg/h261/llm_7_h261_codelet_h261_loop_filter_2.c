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
    uint8_t local_accum[64];
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            yz = y * 8 + x;
            if (x == 0) {
                local_accum[yz] = (temp[yz] + 2) >> 2;
            } else if (x == 7) {
                local_accum[yz] = (temp[yz] + 2) >> 2;
            } else {
                local_accum[yz] = (temp[yz - 1] + 2 * temp[yz] + temp[yz + 1] + 8) >> 4;
            }
        }
    }
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            src[y * stride + x] = local_accum[y * 8 + x];
        }
    }
}
