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
for (y = 0; y < 16; y += 2) {
    src[y * stride] = (temp[y * 8] + 4) >> 3;
    src[y * stride + 15] = (temp[y * 8 + 15] + 4) >> 3;
    for (x = 1; x < 15; x++) {
        xy = y * stride + x;
        yz = y * 8 + x;
        int t0 = temp[yz - 1], t1 = temp[yz], t2 = temp[yz + 1];
        int sum = t0 + 3 * t1 + 2 * t2 + 12;
        src[xy] = sum >> 4;
    }
    if (y + 1 < 16) {
        src[(y+1) * stride] = (temp[(y+1) * 8] + 4) >> 3;
        src[(y+1) * stride + 15] = (temp[(y+1) * 8 + 15] + 4) >> 3;
        for (x = 1; x < 15; x++) {
            xy = (y+1) * stride + x;
            yz = (y+1) * 8 + x;
            src[xy] = (temp[yz - 1] + 2 * temp[yz] + temp[yz + 1] + 8) >> 4;
        }
    }
}
}
