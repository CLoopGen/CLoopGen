#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG i;
extern float *a_offset1;
extern float *a_offset2;
extern float *a_offset3;
extern float *a_offset4;
extern float *a_offset5;
extern float *a_offset6;
extern float *a_offset7;
extern float *a_offset8;
extern float *b_offset;
extern float a1;
extern float a2;
extern float a3;
extern float a4;
extern float a5;
extern float a6;
extern float a7;
extern float a8;
extern float a9;
extern float a10;
extern float a11;
extern float a12;
extern float a13;
extern float a14;
extern float a15;
extern float a16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i += 2) {
    if (i + 1 < m) {
        // Load two elements from each offset for two iterations
        float a1_1 = *(a_offset1 + 0), a2_1 = *(a_offset1 + 1);
        float a3_1 = *(a_offset2 + 0), a4_1 = *(a_offset2 + 1);
        float a5_1 = *(a_offset3 + 0), a6_1 = *(a_offset3 + 1);
        float a7_1 = *(a_offset4 + 0), a8_1 = *(a_offset4 + 1);
        float a9_1 = *(a_offset5 + 0), a10_1 = *(a_offset5 + 1);
        float a11_1 = *(a_offset6 + 0), a12_1 = *(a_offset6 + 1);
        float a13_1 = *(a_offset7 + 0), a14_1 = *(a_offset7 + 1);
        float a15_1 = *(a_offset8 + 0), a16_1 = *(a_offset8 + 1);

        float a1_2 = *(a_offset1 + 2), a2_2 = *(a_offset1 + 3);
        float a3_2 = *(a_offset2 + 2), a4_2 = *(a_offset2 + 3);
        float a5_2 = *(a_offset3 + 2), a6_2 = *(a_offset3 + 3);
        float a7_2 = *(a_offset4 + 2), a8_2 = *(a_offset4 + 3);
        float a9_2 = *(a_offset5 + 2), a10_2 = *(a_offset5 + 3);
        float a11_2 = *(a_offset6 + 2), a12_2 = *(a_offset6 + 3);
        float a13_2 = *(a_offset7 + 2), a14_2 = *(a_offset7 + 3);
        float a15_2 = *(a_offset8 + 2), a16_2 = *(a_offset8 + 3);

        // First store set
        *(b_offset + 0) = a1_1 + a2_1;
        *(b_offset + 1) = a3_1 + a4_1;
        *(b_offset + 2) = a5_1 + a6_1;
        *(b_offset + 3) = a7_1 + a8_1;
        *(b_offset + 4) = a9_1 + a10_1;
        *(b_offset + 5) = a11_1 + a12_1;
        *(b_offset + 6) = a13_1 + a14_1;
        *(b_offset + 7) = a15_1 + a16_1;

        // Second store set
        *(b_offset + 8) = a1_2 + a2_2;
        *(b_offset + 9) = a3_2 + a4_2;
        *(b_offset + 10) = a5_2 + a6_2;
        *(b_offset + 11) = a7_2 + a8_2;
        *(b_offset + 12) = a9_2 + a10_2;
        *(b_offset + 13) = a11_2 + a12_2;
        *(b_offset + 14) = a13_2 + a14_2;
        *(b_offset + 15) = a15_2 + a16_2;

        a_offset1 += 4;
        a_offset2 += 4;
        a_offset3 += 4;
        a_offset4 += 4;
        a_offset5 += 4;
        a_offset6 += 4;
        a_offset7 += 4;
        a_offset8 += 4;
        b_offset += 16;
    } else {
        // Final iteration if m is odd
        a1 = *(a_offset1 + 0);
        a2 = *(a_offset1 + 1);
        a3 = *(a_offset2 + 0);
        a4 = *(a_offset2 + 1);
        a5 = *(a_offset3 + 0);
        a6 = *(a_offset3 + 1);
        a7 = *(a_offset4 + 0);
        a8 = *(a_offset4 + 1);
        a9 = *(a_offset5 + 0);
        a10 = *(a_offset5 + 1);
        a11 = *(a_offset6 + 0);
        a12 = *(a_offset6 + 1);
        a13 = *(a_offset7 + 0);
        a14 = *(a_offset7 + 1);
        a15 = *(a_offset8 + 0);
        a16 = *(a_offset8 + 1);
        *(b_offset + 0) = ((a1) + (a2));
        *(b_offset + 1) = ((a3) + (a4));
        *(b_offset + 2) = ((a5) + (a6));
        *(b_offset + 3) = ((a7) + (a8));
        *(b_offset + 4) = ((a9) + (a10));
        *(b_offset + 5) = ((a11) + (a12));
        *(b_offset + 6) = ((a13) + (a14));
        *(b_offset + 7) = ((a15) + (a16));
        a_offset1 += 2;
        a_offset2 += 2;
        a_offset3 += 2;
        a_offset4 += 2;
        a_offset5 += 2;
        a_offset6 += 2;
        a_offset7 += 2;
        a_offset8 += 2;
        b_offset += 8;
    }
}
}
