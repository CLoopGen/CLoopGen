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
for (i = 0; i < m; i++) {
    for (BLASLONG j = 0; j < 1; j++) { // Artificially nested single-iteration loop
        a1 = *(a_offset1 + 0);
        a2 = *(a_offset1 + 1);
        a3 = *(a_offset2 + 0);
        a4 = *(a_offset2 + 1);
        a5 = *(a_offset3 + 0);
        a6 = *(a_offset3 + 1);
        a7 = *(a_offset4 + 0);
        a8 = *(a_offset4 + 1);
        *(b_offset + 0) = ((a1) + (a2));
        *(b_offset + 1) = ((a3) + (a4));
        *(b_offset + 2) = ((a5) + (a6));
        *(b_offset + 3) = ((a7) + (a8));
    }
    a_offset1 += 2;
    a_offset2 += 2;
    a_offset3 += 2;
    a_offset4 += 2;
    b_offset += 4;
}
}
