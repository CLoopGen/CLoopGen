#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
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
    for (ii = 0; ii < i; ii++) {
        float temp1 = *(a01++);
        float temp2 = *(a02++);
        float temp3 = *(a03++);
        float temp4 = *(a04++);
        float temp5 = *(a05++);
        float temp6 = *(a06++);
        float temp7 = *(a07++);
        float temp8 = *(a08++);
        b[0] = temp1;
        b[1] = temp2;
        b[2] = temp3;
        b[3] = temp4;
        b[4] = temp5;
        b[5] = temp6;
        b[6] = temp7;
        b[7] = temp8;
        b += 8;
    }
}
