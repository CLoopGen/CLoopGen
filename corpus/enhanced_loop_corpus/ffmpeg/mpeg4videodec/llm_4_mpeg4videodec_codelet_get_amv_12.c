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
    for (y = 0; y < 16; y++) {
        int v;
        v = mb_v + (unsigned int)dy * y;
        if (v <= 0) continue;
        for (x = 0; x < 16; x++) {
            sum += v >> shift;
            v += dx;
        }
    }
}
