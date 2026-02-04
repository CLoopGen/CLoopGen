#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
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
    BLASLONG temp_offset;
    for (ii = 0; ii < i; ii++) {
        temp_offset = ii * lda;
        b[0] = a01[temp_offset];
        b[1] = a02[temp_offset];
        b[2] = a03[temp_offset];
        b[3] = a04[temp_offset];
        b[4] = a05[temp_offset];
        b[5] = a06[temp_offset];
        b[6] = a07[temp_offset];
        b[7] = a08[temp_offset];
        b += 8;
    }
}
