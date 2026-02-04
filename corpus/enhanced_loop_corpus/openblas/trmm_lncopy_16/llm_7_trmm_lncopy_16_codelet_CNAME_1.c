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
extern float *a09;
extern float *a10;
extern float *a11;
extern float *a12;
extern float *a13;
extern float *a14;
extern float *a15;
extern float *a16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < i; ii++) {
        b[0] = *(a01 + 0);
        b[1] = *(a01 + 1);  
        b[2] = *(a01 + 2);  
        b[3] = *(a01 + 3);  
        b[4] = *(a01 + 4);  
        b[5] = *(a01 + 5);  
        b[6] = *(a01 + 6);  
        b[7] = *(a01 + 7);  
        b[8] = *(a01 + 8);  
        b[9] = *(a01 + 9);  
        b[10] = *(a01 + 10);
        b[11] = *(a01 + 11);
        b[12] = *(a01 + 12);
        b[13] = *(a01 + 13);
        b[14] = *(a01 + 14);
        b[15] = *(a01 + 15);

        a01 += 16;
        a02++;
        a03++;
        a04++;
        a05++;
        a06++;
        a07++;
        a08++;
        a09++;
        a10++;
        a11++;
        a12++;
        a13++;
        a14++;
        a15++;
        a16++;

        b += 16;
    }
}
