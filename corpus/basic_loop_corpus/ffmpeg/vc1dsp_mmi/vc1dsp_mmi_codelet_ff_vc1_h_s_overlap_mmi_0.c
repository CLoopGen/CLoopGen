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
    a = left[6];
    b = left[7];
    c = right[0];
    d = right[1];
    d1 = a - d;
    d2 = a - d + b - c;
    left[6] = ((a << 3) - d1 + rnd1) >> 3;
    left[7] = ((b << 3) - d2 + rnd2) >> 3;
    right[0] = ((c << 3) + d2 + rnd1) >> 3;
    right[1] = ((d << 3) + d1 + rnd2) >> 3;
    right += right_stride;
    left += left_stride;
    if (flags & 1) {
        rnd2 = 7 - rnd2;
        rnd1 = 7 - rnd1;
    }
}

}
