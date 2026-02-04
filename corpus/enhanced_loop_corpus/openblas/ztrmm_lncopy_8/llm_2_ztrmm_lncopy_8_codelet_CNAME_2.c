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
    float *src[4] = {ao1, ao2, ao3, ao4};
    for (BLASLONG i = 0; i < 4; i++) {
        b[2*i + 0] = src[i][0];
        b[2*i + 1] = src[i][1];
    }
    ao1 += 2;
    ao2 += 2;
    ao3 += 2;
    ao4 += 2;
    b += 8;
}
}
