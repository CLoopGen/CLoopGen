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
    float *b_local = b;
    for (ii = 0; ii < 8; ii++) {
        *(b_local + 0) = *(a01 + ii);
        *(b_local + 1) = *(a02 + ii);
        *(b_local + 2) = *(a03 + ii);
        *(b_local + 3) = *(a04 + ii);
        *(b_local + 4) = *(a05 + ii);
        *(b_local + 5) = *(a06 + ii);
        *(b_local + 6) = *(a07 + ii);
        *(b_local + 7) = *(a08 + ii);

        b_local += 8;
    }

    a01 += 8;
    a02 += 8;
    a03 += 8;
    a04 += 8;
    a05 += 8;
    a06 += 8;
    a07 += 8;
    a08 += 8;
    b += 64;
}
