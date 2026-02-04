#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii++) {
    float *src_array[4] = {a01, a02, a03, a04};
    int offsets[8] = {0, 0, 1, 1, 0, 0, 1, 1};
    int array_indices[8] = {0, 1, 0, 1, 2, 3, 2, 3};

    for (BLASLONG j = 0; j < 8; j++) {
        b[j] = *(src_array[array_indices[j]] + offsets[j]);
    }

    a01 += 2;
    a02 += 2;
    a03 += 2;
    a04 += 2;
    b += 8;
}
}
