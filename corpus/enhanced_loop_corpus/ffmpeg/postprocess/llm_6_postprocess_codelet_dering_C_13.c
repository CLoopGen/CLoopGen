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
    uint8_t val0 = src[stride * y + 0];
    uint8_t val1 = src[stride * y + 1];
    uint8_t val2 = src[stride * y + 2];
    uint8_t val3 = src[stride * y + 3];
    uint8_t val4 = src[stride * y + 4];
    uint8_t val5 = src[stride * y + 5];
    uint8_t val6 = src[stride * y + 6];
    uint8_t val7 = src[stride * y + 7];
    uint8_t val8 = src[stride * y + 8];
    uint8_t val9 = src[stride * y + 9];

    t += (val0 > avg) ? 1 : 0;
    t += (val1 > avg) ? 2 : 0;
    t += (val2 > avg) ? 4 : 0;
    t += (val3 > avg) ? 8 : 0;
    t += (val4 > avg) ? 16 : 0;
    t += (val5 > avg) ? 32 : 0;
    t += (val6 > avg) ? 64 : 0;
    t += (val7 > avg) ? 128 : 0;
    t += (val8 > avg) ? 256 : 0;
    t += (val9 > avg) ? 512 : 0;

    t |= (~t) << 16;
    t &= (t << 1) & (t >> 1);
    s[y] = t;
}
}
