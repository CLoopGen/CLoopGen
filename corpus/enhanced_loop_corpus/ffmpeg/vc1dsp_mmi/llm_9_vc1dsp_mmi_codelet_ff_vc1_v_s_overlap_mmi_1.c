#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *top;
extern int16_t *bottom;
extern int i;
extern int a;
extern int b;
extern int c;
extern int d;
extern int d1;
extern int d2;
extern int rnd1;
extern int rnd2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 4; i++) {
    for (j = 0; j < 2; j++) {
        a = top[48 + j*4];
        b = top[56 + j*4];
        c = bottom[j*4];
        d = bottom[8 + j*4];
        d1 = a - d;
        d2 = b - c;
        top[48 + j*4] = ((a << 2) - d1 + rnd1) >> 2;
        top[56 + j*4] = ((b << 2) - d2 + rnd2) >> 2;
        bottom[j*4] = ((c << 2) + d2 + rnd1) >> 2;
        bottom[8 + j*4] = ((d << 2) + d1 + rnd2) >> 2;
    }
    bottom += 8;
    top += 8;
    rnd2 = 3 - rnd2;
    rnd1 = 3 - rnd1;
}
}
