#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;
extern float *a05;
extern float *a06;
extern float *a07;
extern float *a08;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 4; ii++) {
        float sum1 = *(a01 + 0) + *(a02 + 0) + *(a03 + 0) + *(a04 + 0);
        float sum2 = *(a05 + 0) + *(a06 + 0) + *(a07 + 0) + *(a08 + 0);
        float diff1 = *(a01 + 0) - *(a03 + 0);
        float diff2 = *(a05 + 0) - *(a07 + 0);

        b[0] = sum1;
        b[1] = sum2;
        b[2] = diff1;
        b[3] = diff2;
        b[4] = *(a01 + 0) * *(a08 + 0);
        b[5] = *(a02 + 0) * *(a07 + 0);
        b[6] = *(a03 + 0) * *(a06 + 0);
        b[7] = *(a04 + 0) * *(a05 + 0);

        a01++;
        a02++;
        a03++;
        a04++;
        a05++;
        a06++;
        a07++;
        a08++;
        b += 8;
    }
}
