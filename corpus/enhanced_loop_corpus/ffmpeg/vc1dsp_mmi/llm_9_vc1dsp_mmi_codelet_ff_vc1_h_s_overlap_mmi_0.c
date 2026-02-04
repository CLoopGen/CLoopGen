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
for (i = 0; i < 4; i++) {
    a = left[5];
    b = left[6];
    c = right[1];
    d = right[2];
    d1 = a - d;
    d2 = b - c;
    int sum_ab = a + b;
    int sum_cd = c + d;
    int diff1 = sum_ab - sum_cd;
    int diff2 = (a << 1) - b - d + (c >> 1);
    left[5] = ((a << 2) - diff1 + rnd1) >> 2;
    left[6] = ((b << 2) - diff2 + rnd2) >> 2;
    right[1] = ((c << 2) + diff2 + rnd1) >> 2;
    right[2] = ((d << 2) + diff1 + rnd2) >> 2;
    right += right_stride;
    left += left_stride;
    if (flags & 1) {
        rnd2 ^= 3;
        rnd1 ^= 3;
    }
}
}
