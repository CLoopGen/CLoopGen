#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint8_t pixel;

extern  pixel *pix1;
extern intptr_t stride1;
extern  pixel *pix2;
extern intptr_t stride2;
extern int sums[2][4];
extern int x;
extern int y;
extern int z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (z = 0; z < 2; z++) {
    uint32_t s1 = 0, s2 = 0, ss = 0, s12 = 0;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int a = pix1[x + y * stride1];
            int b = pix2[x + y * stride2];
            s1 += a;
            s2 += b;
            ss += a * a;
            ss += b * b;
            s12 += a * b;
        }
    }
    sums[z][0] = s1;
    sums[z][1] = s2;
    sums[z][2] = ss;
    sums[z][3] = s12;
    pix1 += 4;
    pix2 += 4;
}
}
