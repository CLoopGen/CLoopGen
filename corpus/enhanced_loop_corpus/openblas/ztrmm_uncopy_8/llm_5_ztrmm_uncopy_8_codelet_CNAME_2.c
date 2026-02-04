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
for (ii = 0; ii < 4; ii++) {
    float *srcs[] = {ao1, ao2, ao3, ao4};
    for (BLASLONG j = 0; j < 4; j++) {
        if (j < 2 || ii >= 2) {
            b[2*j + 0] = srcs[j][0];
            b[2*j + 1] = srcs[j][1];
        }
    }
    ao1 += 2;
    ao2 += 2;
    ao3 += 2;
    ao4 += 2;
    b += 8;
}
}
