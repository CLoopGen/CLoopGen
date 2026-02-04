#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t src[];
extern int stride;
extern int y;
extern int avg;
extern int s[10];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 10; y++) {
    int t = 0;
    int offset = stride * y;
    if (!(src[offset + 0] > avg)) goto skip0; t += 1;
    skip0:
    if (!(src[offset + 1] > avg)) goto skip1; t += 2;
    skip1:
    if (!(src[offset + 2] > avg)) goto skip2; t += 4;
    skip2:
    if (!(src[offset + 3] > avg)) goto skip3; t += 8;
    skip3:
    if (!(src[offset + 4] > avg)) goto skip4; t += 16;
    skip4:
    if (!(src[offset + 5] > avg)) goto skip5; t += 32;
    skip5:
    if (!(src[offset + 6] > avg)) goto skip6; t += 64;
    skip6:
    if (!(src[offset + 7] > avg)) goto skip7; t += 128;
    skip7:
    if (!(src[offset + 8] > avg)) goto skip8; t += 256;
    skip8:
    if (!(src[offset + 9] > avg)) goto skip9; t += 512;
    skip9:
    t |= (~t) << 16;
    t &= (t << 1) & (t >> 1);
    s[y] = t;
}
}
