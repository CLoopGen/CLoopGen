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
for (ii = 0; ii < 8; ii++) {
    float *src_array[8] = {a01, a02, a03, a04, a05, a06, a07, a08};
    for (BLASLONG j = 0; j < 8; j++) {
        b[j] = *(src_array[j] + ii);
    }
    b += 8;
}
}
