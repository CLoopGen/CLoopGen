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
    float temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8;
    for (ii = 0; ii < 8; ii++) {
        temp1 = *(a01 + 0);
        temp2 = *(a02 + 0);
        temp3 = *(a03 + 0);
        temp4 = *(a04 + 0);
        temp5 = *(a05 + 0);
        temp6 = *(a06 + 0);
        temp7 = *(a07 + 0);
        temp8 = *(a08 + 0);

        b[0] = temp1;
        b[1] = temp2;
        b[2] = temp3;
        b[3] = temp4;
        b[4] = temp5;
        b[5] = temp6;
        b[6] = temp7;
        b[7] = temp8;

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
