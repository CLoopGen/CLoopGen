#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;
extern float *ao5;
extern float *ao6;
extern float *ao7;
extern float *ao8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 16; ii++) {
        BLASLONG offset = ii >> 3;
        BLASLONG base = (ii & 1) * 2;
        float **a_ptrs[] = {&ao1, &ao2, &ao3, &ao4, &ao5, &ao6, &ao7, &ao8};
        float *src = *(a_ptrs[ii & 7]) + base;
        b[0] = src[0];
        b[1] = src[1];
        b += 2;
        if ((ii & 1) == 1) {
            ao1 += 2; ao2 += 2; ao3 += 2; ao4 += 2;
            ao5 += 2; ao6 += 2; ao7 += 2; ao8 += 2;
        }
    }
}
