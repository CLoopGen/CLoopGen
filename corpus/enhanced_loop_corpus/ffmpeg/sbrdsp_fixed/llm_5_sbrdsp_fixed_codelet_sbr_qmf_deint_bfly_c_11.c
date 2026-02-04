#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *v;
extern  INTFLOAT *src0;
extern  INTFLOAT *src1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        int temp_diff = (int)(16U + src0[i] - src1[63 - i]) >> 5;
        int temp_sum  = (int)(16U + src0[i] + src1[63 - i]) >> 5;

        if (src0[i] >= src1[63 - i]) {
            v[i] = temp_diff;
        } else {
            v[i] = 0;
        }

        if (src0[i] + src1[63 - i] > 0) {
            v[127 - i] = temp_sum;
        } else {
            v[127 - i] = 0;
        }
    }
}
