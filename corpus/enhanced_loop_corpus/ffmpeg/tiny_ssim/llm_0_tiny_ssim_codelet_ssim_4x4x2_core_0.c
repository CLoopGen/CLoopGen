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
    uint32_t s1 = 0, s2 = 0, ss = 0, s12 = 0;
    for (z = 0; z < 8; z++) {
        int a = pix1[z % 4 + (z / 4) * stride1];
        int b = pix2[z % 4 + (z / 4) * stride2];
        s1 += a;
        s2 += b;
        ss += a * a;
        ss += b * b;
        s12 += a * b;

        if ((z % 4) == 3 || z == 7) {
            sums[z / 4][0] = s1;
            sums[z / 4][1] = s2;
            sums[z / 4][2] = ss;
            sums[z / 4][3] = s12;
            s1 = s2 = ss = s12 = 0;
            if (z == 3) {
                pix1 += 4;
                pix2 += 4;
            }
        }
    }
}
