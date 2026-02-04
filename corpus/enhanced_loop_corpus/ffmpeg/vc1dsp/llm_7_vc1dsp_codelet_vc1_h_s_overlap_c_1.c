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
    
    int orig_a = a, orig_d = d, orig_b = b, orig_c = c;
    
    d1 = orig_a - orig_d;
    d2 = orig_a - orig_d + orig_b - orig_c;
    
    int new_left6 = ((a * 8) - d1 + rnd1) >> 3;
    int new_left7 = ((b * 8) - d2 + rnd2) >> 3;
    int new_right0 = ((c * 8) + d2 + rnd1) >> 3;
    int new_right1 = ((d * 8) + d1 + rnd2) >> 3;
    
    left[6] = new_left6;
    left[7] = new_left7;
    right[0] = new_right0;
    right[1] = new_right1;
    
    right += right_stride;
    left += left_stride;
    
    if (flags & 1) {
        int temp_rnd1 = rnd1;
        int temp_rnd2 = rnd2;
        rnd1 = 7 - temp_rnd2;
        rnd2 = 7 - temp_rnd1;
    }
}
}
