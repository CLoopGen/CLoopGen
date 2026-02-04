#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG temp_offset = 0;
for (ii = 0; ii < i; ii++) {
    b[0] = ao1[temp_offset + 0];
    b[1] = ao1[temp_offset + 1];
    b[2] = ao1[temp_offset + 2];
    b[3] = ao1[temp_offset + 3];
    temp_offset += lda;
    b += 4;
}
}
