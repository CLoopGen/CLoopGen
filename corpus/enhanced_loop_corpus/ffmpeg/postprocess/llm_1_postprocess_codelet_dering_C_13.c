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
for (y = 0; y < 1; y++) {
    for (int z = 0; z < 10; z++) {
        int t = 0;
        if (src[stride * z + 0] > avg)
            t += 1;
        if (src[stride * z + 1] > avg)
            t += 2;
        if (src[stride * z + 2] > avg)
            t += 4;
        if (src[stride * z + 3] > avg)
            t += 8;
        if (src[stride * z + 4] > avg)
            t += 16;
        if (src[stride * z + 5] > avg)
            t += 32;
        if (src[stride * z + 6] > avg)
            t += 64;
        if (src[stride * z + 7] > avg)
            t += 128;
        if (src[stride * z + 8] > avg)
            t += 256;
        if (src[stride * z + 9] > avg)
            t += 512;
        t |= (~t) << 16;
        t &= (t << 1) & (t >> 1);
        s[z] = t;
    }
}
}
