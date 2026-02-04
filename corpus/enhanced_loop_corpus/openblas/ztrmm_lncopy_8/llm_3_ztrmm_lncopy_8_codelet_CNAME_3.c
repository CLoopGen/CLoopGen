#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii++) {
    // Variant 2: Strided memory access pattern with interleaved pointer increments
    // Introduce strided access by updating pointers after each write pair to change access order
    b[0] = ao1[0]; b[1] = ao1[1]; ao1 += 2;
    b[2] = ao2[0]; b[3] = ao2[1]; ao2 += 2;
    b[4] = ao3[0]; b[5] = ao3[1]; ao3 += 2;
    b[6] = ao4[0]; b[7] = ao4[1]; ao4 += 2;

    // Advance destination in fixed stride
    b += 8;
}
}
