#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG n;
extern float beta;
extern BLASLONG ldc;
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG chunk;
extern BLASLONG remain;
extern float *c_offset1;
extern float *c_offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = n; j > 0; j--) {
    c_offset1 = c_offset;
    c_offset += ldc;
    for (i = chunk; i > 0; i--) {
        float temp0 = *(c_offset1 + 0) * beta;
        float temp1 = *(c_offset1 + 1) * beta;
        float temp2 = *(c_offset1 + 2) * beta;
        float temp3 = *(c_offset1 + 3) * beta;
        float temp4 = *(c_offset1 + 4) * beta;
        float temp5 = *(c_offset1 + 5) * beta;
        float temp6 = *(c_offset1 + 6) * beta;
        float temp7 = *(c_offset1 + 7) * beta;
        *(c_offset1 + 0) = temp0;
        *(c_offset1 + 1) = temp1;
        *(c_offset1 + 2) = temp2;
        *(c_offset1 + 3) = temp3;
        *(c_offset1 + 4) = temp4;
        *(c_offset1 + 5) = temp5;
        *(c_offset1 + 6) = temp6;
        *(c_offset1 + 7) = temp7;
        c_offset1 += 8;
    }
    for (i = remain; i > 0; i--) {
        float temp = *c_offset1 * beta;
        *c_offset1 = temp;
        c_offset1++;
    }
}
}
