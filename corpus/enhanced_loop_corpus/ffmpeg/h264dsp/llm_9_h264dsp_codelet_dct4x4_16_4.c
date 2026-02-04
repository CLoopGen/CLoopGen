#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 2; y++) {
    for (x = 0; x < 4; x += 2) {
        static const int scale[] = {13107 * 10, 8066 * 13, 5243 * 16};
        const int idx1 = (y & 1) + (x & 1);
        const int idx2 = (y & 1) + ((x + 1) & 1);
        int temp1 = coef[y * 4 + x];
        int temp2 = coef[y * 4 + x + 1];
        coef[y * 4 + x] = (temp1 * scale[idx1] + (1 << 13)) >> 14;
        coef[y * 4 + x + 1] = (temp2 * scale[idx2] + (1 << 13)) >> 14;
    }
}
}
