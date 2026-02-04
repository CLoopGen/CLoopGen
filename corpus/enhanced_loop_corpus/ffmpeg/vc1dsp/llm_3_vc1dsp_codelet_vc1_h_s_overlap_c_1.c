#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *left;
extern int16_t *right;
extern int left_stride;
extern int right_stride;
extern int flags;
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
    ptrdiff_t idx_left = 6;
    ptrdiff_t idx_right = 0;
    
    a = left[idx_left + 0];
    b = left[idx_left + 1];
    c = right[idx_right + 0];
    d = right[idx_right + 1];
    d1 = a - d;
    d2 = a - d + b - c;
    left[idx_left + 0] = ((a * 8) - d1 + rnd1) >> 3;
    left[idx_left + 1] = ((b * 8) - d2 + rnd2) >> 3;
    right[idx_right + 0] = ((c * 8) + d2 + rnd1) >> 3;
    right[idx_right + 1] = ((d * 8) + d1 + rnd2) >> 3;
    
    right += right_stride;
    left += left_stride;
    if (flags & 1) {
        rnd2 = 7 - rnd2;
        rnd1 = 7 - rnd1;
    }
}
}
