#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG n;
extern BLASLONG ldc;
extern BLASLONG i;
extern BLASLONG j;
extern float *c_offset;
extern float *c_offset1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = n; j > 0; j--) {
    c_offset1 = c_offset;
    c_offset += ldc;
    BLASLONG vector_count = (m >> 2);
    BLASLONG residual = m - (vector_count << 2);

    for (BLASLONG v = 0; v < vector_count; v++) {
        float temp0 = *(c_offset1 + 0), temp1 = *(c_offset1 + 1);
        float temp2 = *(c_offset1 + 2), temp3 = *(c_offset1 + 3);
        float temp4 = *(c_offset1 + 4), temp5 = *(c_offset1 + 5);
        float temp6 = *(c_offset1 + 6), temp7 = *(c_offset1 + 7);
        temp0 = temp1 = temp2 = temp3 = 0.F;
        temp4 = temp5 = temp6 = temp7 = 0.F;
        *(c_offset1 + 0) = temp0; *(c_offset1 + 1) = temp1;
        *(c_offset1 + 2) = temp2; *(c_offset1 + 3) = temp3;
        *(c_offset1 + 4) = temp4; *(c_offset1 + 5) = temp5;
        *(c_offset1 + 6) = temp6; *(c_offset1 + 7) = temp7;
        c_offset1 += 8;
    }

    for (BLASLONG r = 0; r < residual; r++) {
        float temp_val = 0.F;
        *(c_offset1) = temp_val;
        c_offset1++;
    }
}
}
