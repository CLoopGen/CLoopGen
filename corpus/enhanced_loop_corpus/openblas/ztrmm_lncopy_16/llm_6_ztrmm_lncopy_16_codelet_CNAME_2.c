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
    float temp1, temp2;
    for (ii = 0; ii < 8; ii++) {
        temp1 = *(a01 + 0);
        temp2 = *(a01 + 1);
        b[0] = temp1;
        b[1] = temp2;

        temp1 = *(a02 + 0);
        temp2 = *(a02 + 1);
        b[2] = temp1;
        b[3] = temp2;

        temp1 = *(a03 + 0);
        temp2 = *(a03 + 1);
        b[4] = temp1;
        b[5] = temp2;

        temp1 = *(a04 + 0);
        temp2 = *(a04 + 1);
        b[6] = temp1;
        b[7] = temp2;

        temp1 = *(a05 + 0);
        temp2 = *(a05 + 1);
        b[8] = temp1;
        b[9] = temp2;

        temp1 = *(a06 + 0);
        temp2 = *(a06 + 1);
        b[10] = temp1;
        b[11] = temp2;

        temp1 = *(a07 + 0);
        temp2 = *(a07 + 1);
        b[12] = temp1;
        b[13] = temp2;

        temp1 = *(a08 + 0);
        temp2 = *(a08 + 1);
        b[14] = temp1;
        b[15] = temp2;

        a01 += 2;
        a02 += 2;
        a03 += 2;
        a04 += 2;
        a05 += 2;
        a06 += 2;
        a07 += 2;
        a08 += 2;
        b += 16;
    }
}
