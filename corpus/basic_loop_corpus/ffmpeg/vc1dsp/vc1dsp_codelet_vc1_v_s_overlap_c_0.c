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
    d2 = a - d + b - c;
    top[48] = ((a * 8) - d1 + rnd1) >> 3;
    top[56] = ((b * 8) - d2 + rnd2) >> 3;
    bottom[0] = ((c * 8) + d2 + rnd1) >> 3;
    bottom[8] = ((d * 8) + d1 + rnd2) >> 3;
    bottom++;
    top++;
    rnd2 = 7 - rnd2;
    rnd1 = 7 - rnd1;
}

}
