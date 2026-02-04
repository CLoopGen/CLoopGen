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
    float *b_local = b;
    BLASLONG ii_local = 0;
    while (ii_local < i) {
        b_local[7] = *(a08 + 0);
        b_local[6] = *(a07 + 0);
        b_local[5] = *(a06 + 0);
        b_local[4] = *(a05 + 0);
        b_local[3] = *(a04 + 0);
        b_local[2] = *(a03 + 0);
        b_local[1] = *(a02 + 0);
        b_local[0] = *(a01 + 0);
        a01++; a02++; a03++; a04++; a05++; a06++; a07++; a08++;
        b_local += 8;
        ii_local++;
    }
}
