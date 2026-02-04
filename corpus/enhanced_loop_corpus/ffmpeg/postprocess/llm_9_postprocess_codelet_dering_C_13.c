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
    int t1 = 0, t2 = 0;
    for (int x = 0; x < 5; x++) {
        if (src[stride * y + x] > avg)
            t1 += (1 << x);
        if (src[stride * y + 5 + x] > avg)
            t2 += (1 << x);
    }
    t1 |= (~t1) << 16;
    t1 &= (t1 << 1) & (t1 >> 1);
    t2 |= (~t2) << 16;
    t2 &= (t2 << 1) & (t2 >> 1);
    s[y] = t1 ^ t2;
}
}
