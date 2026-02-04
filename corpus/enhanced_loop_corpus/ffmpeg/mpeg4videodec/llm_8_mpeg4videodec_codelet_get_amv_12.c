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
for (y = 0; y < 32; y++) {
    int v;
    v = mb_v + (unsigned int)dy * y;
    for (x = 0; x < 8; x++) {
        sum += (v >> shift) + (v << 1);
        v += dx + 1;
    }
}
}
