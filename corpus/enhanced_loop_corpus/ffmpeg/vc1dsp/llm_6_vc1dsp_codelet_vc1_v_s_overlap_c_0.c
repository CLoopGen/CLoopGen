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
for (i = 0; i < 8; i++) {
    a = top[48];
    b = top[56];
    c = bottom[0];
    d = bottom[8];
    d1 = a - d;
    d2 = b - c;
    int temp1 = ((a * 8) - d1 + rnd1) >> 3;
    int temp2 = ((b * 8) - (d1 + d2) + rnd2) >> 3;
    int temp3 = ((c * 8) + (d1 + d2) + rnd1) >> 3;
    int temp4 = ((d * 8) + d1 + rnd2) >> 3;
    top[48] = temp1;
    top[56] = temp2;
    bottom[0] = temp3;
    bottom[8] = temp4;
    top++;
    bottom++;
    rnd2 = 7 - rnd2;
    rnd1 = 7 - rnd1;
}
}
