#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
static const int access_order[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
for (int i = 0; i < 16; i++) {
    int linear_idx = access_order[i];
    int y = linear_idx / 4;
    int x = linear_idx % 4;
    static const int scale[] = {13107 * 10, 8066 * 13, 5243 * 16};
    const int idx = (y & 1) + (x & 1);
    coef[linear_idx] = (coef[linear_idx] * scale[idx] + (1 << 14)) >> 15;
}
}
