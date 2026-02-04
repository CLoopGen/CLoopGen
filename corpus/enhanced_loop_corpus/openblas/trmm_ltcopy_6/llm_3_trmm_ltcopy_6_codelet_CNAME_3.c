#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *a_offset = ao1;
for (ii = 0; ii < i; ii++) {
    *(b + 0) = a_offset[0];
    *(b + 1) = a_offset[1];
    *(b + 2) = a_offset[2];
    *(b + 3) = a_offset[3];
    a_offset += 4;
    b += 4;
}
}
