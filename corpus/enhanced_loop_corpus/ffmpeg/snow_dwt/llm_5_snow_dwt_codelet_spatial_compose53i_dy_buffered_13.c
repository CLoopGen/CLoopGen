#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern int width;
extern IDWTELEM *b0;
extern IDWTELEM *b1;
extern IDWTELEM *b2;
extern IDWTELEM *b3;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < width; x++) {
        int temp_sum1 = b1[x] + b3[x] + 2;
        int shift_val1 = temp_sum1 >> 2;
        b2[x] -= shift_val1;

        int temp_sum2 = b0[x] + b2[x];
        if (temp_sum2 != 0) {
            int shift_val2 = temp_sum2 >> 1;
            b1[x] += shift_val2;
        }
    }
}
