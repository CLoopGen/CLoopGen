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
float *local_b = b;
for (ii = 0; ii < 16; ii++) {
    *(local_b + 0) = *(a01 + 0);
    *(local_b + 1) = *(a01 + 1);
    *(local_b + 2) = *(a02 + 0);
    *(local_b + 3) = *(a02 + 1);
    *(local_b + 4) = *(a03 + 0);
    *(local_b + 5) = *(a03 + 1);
    *(local_b + 6) = *(a04 + 0);
    *(local_b + 7) = *(a04 + 1);
    *(local_b + 8) = *(a05 + 0);
    *(local_b + 9) = *(a05 + 1);
    *(local_b + 10) = *(a06 + 0);
    *(local_b + 11) = *(a06 + 1);
    *(local_b + 12) = *(a07 + 0);
    *(local_b + 13) = *(a07 + 1);
    *(local_b + 14) = *(a08 + 0);
    *(local_b + 15) = *(a08 + 1);
    *(local_b + 16) = *(a09 + 0);
    *(local_b + 17) = *(a09 + 1);
    *(local_b + 18) = *(a10 + 0);
    *(local_b + 19) = *(a10 + 1);
    *(local_b + 20) = *(a11 + 0);
    *(local_b + 21) = *(a11 + 1);
    *(local_b + 22) = *(a12 + 0);
    *(local_b + 23) = *(a12 + 1);
    *(local_b + 24) = *(a13 + 0);
    *(local_b + 25) = *(a13 + 1);
    *(local_b + 26) = *(a14 + 0);
    *(local_b + 27) = *(a14 + 1);
    *(local_b + 28) = *(a15 + 0);
    *(local_b + 29) = *(a15 + 1);
    *(local_b + 30) = *(a16 + 0);
    *(local_b + 31) = *(a16 + 1);

    a01 += 2;
    a02 += 2;
    a03 += 2;
    a04 += 2;
    a05 += 2;
    a06 += 2;
    a07 += 2;
    a08 += 2;
    a09 += 2;
    a10 += 2;
    a11 += 2;
    a12 += 2;
    a13 += 2;
    a14 += 2;
    a15 += 2;
    a16 += 2;
    local_b += 32;
}
b = local_b;
}
