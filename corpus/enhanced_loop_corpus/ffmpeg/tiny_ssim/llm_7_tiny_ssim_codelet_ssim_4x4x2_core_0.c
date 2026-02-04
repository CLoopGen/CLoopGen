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
    uint32_t temp_sums[4] = {0};
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int idx = x + y * (z == 0 ? stride1 : stride2);
            int a = pix1[idx];
            int b = pix2[idx];
            temp_sums[0] += a;
            temp_sums[1] += b;
            temp_sums[2] += a*a + b*b;
            temp_sums[3] += a*b;
        }
    }
    for (int i = 0; i < 4; i++) {
        sums[z][i] = temp_sums[i];
    }
    pix1 += 4;
    pix2 += 4;
}
}
