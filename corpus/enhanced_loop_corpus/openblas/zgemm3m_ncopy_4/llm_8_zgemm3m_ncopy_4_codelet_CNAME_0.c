#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG i;
extern float *a_offset1;
extern float *a_offset2;
extern float *a_offset3;
extern float *a_offset4;
extern float *b_offset;
extern float a1;
extern float a2;
extern float a3;
extern float a4;
extern float a5;
extern float a6;
extern float a7;
extern float a8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i += 2) {
    if (i + 1 < m) {
        // Process two iterations at once to increase computational intensity
        float a1_0 = *(a_offset1 + 0);
        float a2_0 = *(a_offset1 + 1);
        float a3_0 = *(a_offset2 + 0);
        float a4_0 = *(a_offset2 + 1);
        float a5_0 = *(a_offset3 + 0);
        float a6_0 = *(a_offset3 + 1);
        float a7_0 = *(a_offset4 + 0);
        float a8_0 = *(a_offset4 + 1);

        float a1_1 = *(a_offset1 + 2);
        float a2_1 = *(a_offset1 + 3);
        float a3_1 = *(a_offset2 + 2);
        float a4_1 = *(a_offset2 + 3);
        float a5_1 = *(a_offset3 + 2);
        float a6_1 = *(a_offset3 + 3);
        float a7_1 = *(a_offset4 + 2);
        float a8_1 = *(a_offset4 + 3);

        *(b_offset + 0) = a1_0 + a2_0;
        *(b_offset + 1) = a3_0 + a4_0;
        *(b_offset + 2) = a5_0 + a6_0;
        *(b_offset + 3) = a7_0 + a8_0;

        *(b_offset + 4) = a1_1 + a2_1;
        *(b_offset + 5) = a3_1 + a4_1;
        *(b_offset + 6) = a5_1 + a6_1;
        *(b_offset + 7) = a7_1 + a8_1;

        a_offset1 += 4;
        a_offset2 += 4;
        a_offset3 += 4;
        a_offset4 += 4;
        b_offset += 8;
    } else {
        // Handle leftover iteration
        a1 = *(a_offset1 + 0);
        a2 = *(a_offset1 + 1);
        a3 = *(a_offset2 + 0);
        a4 = *(a_offset2 + 1);
        a5 = *(a_offset3 + 0);
        a6 = *(a_offset3 + 1);
        a7 = *(a_offset4 + 0);
        a8 = *(a_offset4 + 1);
        *(b_offset + 0) = a1 + a2;
        *(b_offset + 1) = a3 + a4;
        *(b_offset + 2) = a5 + a6;
        *(b_offset + 3) = a7 + a8;

        a_offset1 += 2;
        a_offset2 += 2;
        a_offset3 += 2;
        a_offset4 += 2;
        b_offset += 4;
    }
}
}
