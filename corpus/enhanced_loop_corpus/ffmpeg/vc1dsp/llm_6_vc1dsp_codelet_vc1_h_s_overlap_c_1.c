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
    int16_t *l6 = &left[6];
    int16_t *l7 = &left[7];
    int16_t *r0 = &right[0];
    int16_t *r1 = &right[1];
    
    a = *l6;
    b = *l7;
    c = *r0;
    d = *r1;
    
    int temp1 = (a * 8) + rnd1;
    int temp2 = (b * 8) + rnd2;
    int temp3 = (c * 8) + rnd1;
    int temp4 = (d * 8) + rnd2;
    
    d1 = a - d;
    d2 = a - d + b - c;
    
    *l6 = (temp1 - d1) >> 3;
    *l7 = (temp2 - d2) >> 3;
    *r0 = (temp3 + d2) >> 3;
    *r1 = (temp4 + d1) >> 3;
    
    right += right_stride;
    left += left_stride;
    
    if (flags & 1) {
        rnd2 = 7 - rnd2;
        rnd1 = 7 - rnd1;
    }
}
}
