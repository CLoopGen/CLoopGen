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
    int base_idx = stride * y;
    // Change memory access to non-consecutive strided pattern: access every other element first, then the rest
    for (int offset = 0; offset < 2; offset++) {
        for (int x = offset; x < 10; x += 2) {
            if (src[base_idx + x] > avg) {
                if (x == 0 || x == 2 || x == 4 || x == 6 || x == 8)
                    t += (1 << x);
                else
                    t += (1 << x);
            }
        }
    }
    t |= (~t) << 16;
    t &= (t << 1) & (t >> 1);
    s[y] = t;
}
}
