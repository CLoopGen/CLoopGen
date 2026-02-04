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
        for (BLASLONG j = 0; j < 1; j++) {  // Introduce a nested inner loop of fixed depth
            b[0] = ao1[j];
            b[1] = ao2[j];
            b[2] = ao3[j];
            b[3] = ao4[j];
        }
        ao1++;
        ao2++;
        ao3++;
        ao4++;
        b += 4;
    }
}
