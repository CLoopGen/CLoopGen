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
    b[0] = *(a01 + 0);
    if (ii > i / 2) {
        b[1] = *(a02 + 0);
        b[2] = *(a03 + 0);
        b[3] = *(a04 + 0);
        b[4] = *(a05 + 0);
        b[5] = *(a06 + 0);
        b[6] = *(a07 + 0);
        b[7] = *(a08 + 0);
    } else {
        b[1] = 0.0f;
        b[2] = 0.0f;
        b[3] = 0.0f;
        b[4] = 0.0f;
        b[5] = 0.0f;
        b[6] = 0.0f;
        b[7] = 0.0f;
    }
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
