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
    for (int x = 0; x < 10; x++) {
        if (src[stride * y + x] > avg)
            t += (1 << x);
    }
    t |= (~t) << 16;
    t &= (t << 1) & (t >> 1);
    s[y] = t;
}
}
