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
    uint8_t *row = &src[stride * y];
    t += (row[0] > avg) ? 1 : 0;
    t += (row[1] > avg) ? 2 : 0;
    t += (row[2] > avg) ? 4 : 0;
    t += (row[3] > avg) ? 8 : 0;
    t += (row[4] > avg) ? 16 : 0;
    t += (row[5] > avg) ? 32 : 0;
    t += (row[6] > avg) ? 64 : 0;
    t += (row[7] > avg) ? 128 : 0;
    t += (row[8] > avg) ? 256 : 0;
    t += (row[9] > avg) ? 512 : 0;
    t |= (~t) << 16;
    t &= (t << 1) & (t >> 1);
    s[y] = t;
}
}
