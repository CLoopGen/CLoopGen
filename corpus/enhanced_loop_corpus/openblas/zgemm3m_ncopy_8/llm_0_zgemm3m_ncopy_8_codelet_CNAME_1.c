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
        // Process two iterations at once
        float a1_1, a2_1, a3_1, a4_1, a5_1, a6_1, a7_1, a8_1;
        float a1_2, a2_2, a3_2, a4_2, a5_2, a6_2, a7_2, a8_2;

        // First iteration (i)
        a1_1 = *(a_offset1 + 0);
        a2_1 = *(a_offset1 + 1);
        a3_1 = *(a_offset2 + 0);
        a4_1 = *(a_offset2 + 1);
        a5_1 = *(a_offset3 + 0);
        a6_1 = *(a_offset3 + 1);
        a7_1 = *(a_offset4 + 0);
        a8_1 = *(a_offset4 + 1);

        *(b_offset + 0) = a1_1 + a2_1;
        *(b_offset + 1) = a3_1 + a4_1;
        *(b_offset + 2) = a5_1 + a6_1;
        *(b_offset + 3) = a7_1 + a8_1;

        // Second iteration (i+1)
        a1_2 = *(a_offset1 + 2);
        a2_2 = *(a_offset1 + 3);
        a3_2 = *(a_offset2 + 2);
        a4_2 = *(a_offset2 + 3);
        a5_2 = *(a_offset3 + 2);
        a6_2 = *(a_offset3 + 3);
        a7_2 = *(a_offset4 + 2);
        a8_2 = *(a_offset4 + 3);

        *(b_offset + 4) = a1_2 + a2_2;
        *(b_offset + 5) = a3_2 + a4_2;
        *(b_offset + 6) = a5_2 + a6_2;
        *(b_offset + 7) = a7_2 + a8_2;

        a_offset1 += 4;
        a_offset2 += 4;
        a_offset3 += 4;
        a_offset4 += 4;
        b_offset += 8;
    } else {
        // Final odd iteration
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
