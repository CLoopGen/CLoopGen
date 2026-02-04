#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    static const int scale[] = {13107 * 10, 8066 * 13, 5243 * 16};
    for (int i = 0; i < 16; i++) {
        int y = i >> 2;
        int x = i & 3;
        const int idx = (y & 1) + (x & 1);
        coef[i] = (coef[i] * scale[idx] + (1 << 14)) >> 15;
    }
}
