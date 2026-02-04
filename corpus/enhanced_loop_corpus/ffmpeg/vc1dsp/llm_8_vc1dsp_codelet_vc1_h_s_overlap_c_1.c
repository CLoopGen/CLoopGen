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
for (i = 0; i < 16; i++) {
    a = left[6];
    b = left[7];
    c = right[0];
    d = right[1];
    d1 = a - d;
    d2 = a - d + b - c;
    int temp1 = ((a * 8) - d1 + rnd1) >> 3;
    int temp2 = ((b * 8) - d2 + rnd2) >> 3;
    int temp3 = ((c * 8) + d2 + rnd1) >> 3;
    int temp4 = ((d * 8) + d1 + rnd2) >> 3;
    left[6] = temp1;
    left[7] = temp2;
    right[0] = temp3;
    right[1] = temp4;
    right += right_stride;
    left += left_stride;
    if (flags & 1) {
        rnd2 = 7 - rnd2;
        rnd1 = 7 - rnd1;
    }
}
}
