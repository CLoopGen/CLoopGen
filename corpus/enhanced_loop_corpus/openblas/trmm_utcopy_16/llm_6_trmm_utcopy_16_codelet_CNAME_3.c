#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG temp_offset = 0;
for (ii = 0; ii < i; ii++) {
    temp_offset = ii * lda;
    b[0] = a01[temp_offset + 0];
    b[1] = a01[temp_offset + 1];
    b[2] = a01[temp_offset + 2];
    b[3] = a01[temp_offset + 3];
    b[4] = a01[temp_offset + 4];
    b[5] = a01[temp_offset + 5];
    b[6] = a01[temp_offset + 6];
    b[7] = a01[temp_offset + 7];
    b += 8;
}
}
