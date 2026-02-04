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
    pixel *p1 = pix1;
    pixel *p2 = pix2;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int a = p1[x];
            int b = p2[x];
            s1 += a;
            s2 += b;
            ss += a * a + b * b;
            s12 += a * b;
        }
        p1 += stride1;
        p2 += stride2;
    }
    sums[z][0] = s1;
    sums[z][1] = s2;
    sums[z][2] = ss;
    sums[z][3] = s12;
    pix1 += 4;
    pix2 += 4;
}
}
