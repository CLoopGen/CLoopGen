#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern int mb_v;
extern int sum;
extern int dx;
extern int dy;
extern int shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; y++) {
    int v = mb_v + (unsigned int)dy * y;
    for (x = 0; x < 8; x++) {
        sum += (v >> shift) & 0xFF;
        v += dx;
        if (sum > 1000) {
            sum -= 50;
        }
    }
}
}
