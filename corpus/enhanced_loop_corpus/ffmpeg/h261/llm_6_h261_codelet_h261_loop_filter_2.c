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
    uint8_t temp_src[8];
    for (y = 0; y < 8; y++) {
        int base_temp = y * 8;
        temp_src[0] = (temp[base_temp] + 2) >> 2;
        temp_src[7] = (temp[base_temp + 7] + 2) >> 2;
        for (x = 1; x < 7; x++) {
            xy = y * stride + x;
            yz = base_temp + x;
            temp_src[x] = (temp[yz - 1] + 2 * temp[yz] + temp[yz + 1] + 8) >> 4;
        }
        for (x = 0; x < 8; x++) {
            src[y * stride + x] = temp_src[x];
        }
    }
}
