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
    uint32_t s1[2], s2[2], ss[2], s12[2];
    for (z = 0; z < 2; z++) {
        s1[z] = s2[z] = ss[z] = s12[z] = 0;
        for (y = 0; y < 4; y++) {
            for (x = 0; x < 4; x++) {
                int a = pix1[x + y * stride1];
                int b = pix2[x + y * stride2];
                s1[z] += a;
                s2[z] += b;
                ss[z] += a * a + b * b;
                s12[z] += a * b;
            }
        }
        sums[z][0] = s1[z];
        sums[z][1] = s2[z];
        sums[z][2] = ss[z];
        sums[z][3] = s12[z];
        pix1 += 4;
        pix2 += 4;
    }
}
