#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *local_b = b;
    for (ii = 0; ii < 2; ii++) {
        *(local_b + 0) = ao1[0];
        *(local_b + 1) = ao2[0];
        *(local_b + 2) = ao3[0];
        *(local_b + 3) = ao4[0];
        local_b += 4;
    }
    b = local_b;
    ao1 += 2;
    ao2 += 2;
    ao3 += 2;
    ao4 += 2;
}
