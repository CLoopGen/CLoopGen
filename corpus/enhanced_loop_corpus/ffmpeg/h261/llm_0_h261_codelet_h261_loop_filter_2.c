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
    for (y = 0; y < 8; y++) {
        src[y * stride] = (temp[y * 8] + 2) >> 2;
        src[y * stride + 7] = (temp[y * 8 + 7] + 2) >> 2;
        x = 1;
        xy = y * stride + x;
        yz = y * 8 + x;
        src[xy] = (temp[yz - 1] + 2 * temp[yz] + temp[yz + 1] + 8) >> 4;
        x = 2;
        xy = y * stride + x;
        yz = y * 8 + x;
        src[xy] = (temp[yz - 1] + 2 * temp[yz] + temp[yz + 1] + 8) >> 4;
        x = 3;
        xy = y * stride + x;
        yz = y * 8 + x;
        src[xy] = (temp[yz - 1] + 2 * temp[yz] + temp[yz + 1] + 8) >> 4;
        x = 4;
        xy = y * stride + x;
        yz = y * 8 + x;
        src[xy] = (temp[yz - 1] + 2 * temp[yz] + temp[yz + 1] + 8) >> 4;
        x = 5;
        xy = y * stride + x;
        yz = y * 8 + x;
        src[xy] = (temp[yz - 1] + 2 * temp[yz] + temp[yz + 1] + 8) >> 4;
        x = 6;
        xy = y * stride + x;
        yz = y * 8 + x;
        src[xy] = (temp[yz - 1] + 2 * temp[yz] + temp[yz + 1] + 8) >> 4;
    }
}
