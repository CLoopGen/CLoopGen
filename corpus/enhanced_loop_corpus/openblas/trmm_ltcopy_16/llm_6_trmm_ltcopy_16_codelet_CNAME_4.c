#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG temp_offset = 0;
for (ii = 0; ii < 4; ii++) {
    b[0] = a01[temp_offset + 0];
    b[1] = a01[temp_offset + 1];
    b[2] = a01[temp_offset + 2];
    b[3] = a01[temp_offset + 3];
    temp_offset += lda;
    b += 4;
}
}
