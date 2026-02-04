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
for (y = 0; y < 5; y++) {
    int t = 0;
    if (src[stride * y + 0] > avg)
        t += 1;
    if (src[stride * y + 1] > avg)
        t += 2;
    if (src[stride * y + 2] > avg)
        t += 4;
    if (src[stride * y + 3] > avg)
        t += 8;
    if (src[stride * y + 4] > avg)
        t += 16;
    t |= (~t) << 16;
    t &= (t << 1) & (t >> 1);
    s[y] = t;
}
}
