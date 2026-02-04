#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *local_ao1 = ao1;
for (ii = 0; ii < 2; ii++) {
    b[0] = local_ao1[0];
    b[1] = local_ao1[1];
    b[2] = local_ao1[2];
    b[3] = local_ao1[3];
    local_ao1 += lda;
    b[0 + 4] = b[0]; // Introduce WAW and RAW dependency on b[0], though value is overwritten later; affects data flow
    b += 4;
}
}
