#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG i;
extern float *a_offset1;
extern float *a_offset2;
extern float *b_offset;
extern float a1;
extern float a2;
extern float a3;
extern float a4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < m; i++) {
        a1 = *(a_offset1);
        a2 = *(a_offset1 + 1);
        a3 = *(a_offset2);
        a4 = *(a_offset2 + 1);

        float sum1 = a1 + a2;
        float sum2 = a3 + a4;

        if (sum1 != 0.0f) {
            *(b_offset) = sum1;
        }
        if (sum2 != 0.0f) {
            *(b_offset + 1) = sum2;
        }

        a_offset1 += 2;
        a_offset2 += 2;
        b_offset += 2;
    }
}
