#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 4; ++ii) {
    if (ii % 2 == 0) {
        b[0] = a01[0];
        b[1] = a01[1];
        b[2] = a01[2];
        b[3] = a01[3];
        b[4] = a01[4];
        b[5] = a01[5];
        b[6] = a01[6];
        b[7] = a01[7];
    } else {
        for (int j = 0; j < 8; ++j) {
            b[j] = a01[j];
        }
    }
    a01 += lda;
    b += 8;
}
}
