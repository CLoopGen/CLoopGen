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
for (ii = 0; ii < 8; ii++) {
    float *ptrs[8] = {ao1, ao2, ao3, ao4, ao5, ao6, ao7, ao8};
    BLASLONG idx;
    for (idx = 0; idx < 8; idx++) {
        b[idx * 2 + 0] = ptrs[idx][ii * 2 + 0];
        b[idx * 2 + 1] = ptrs[idx][ii * 2 + 1];
    }
    b += 16;
}
}
