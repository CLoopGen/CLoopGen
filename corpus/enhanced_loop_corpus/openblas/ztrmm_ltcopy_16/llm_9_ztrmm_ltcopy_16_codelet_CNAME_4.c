#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 2; ii++) {
    b[0] = *(a01 + 0) * 2.0f;
    b[1] = *(a01 + 1) * 2.0f;
    b[2] = *(a01 + 2) * 2.0f;
    b[3] = *(a01 + 3) * 2.0f;
    b[4] = *(a01 + 4) * 2.0f;
    b[5] = *(a01 + 5) * 2.0f;
    b[6] = *(a01 + 6) * 2.0f;
    b[7] = *(a01 + 7) * 2.0f;
    a01 += lda;
    b += 8;

    // Additional computational work to increase intensity
    b[0] += *(a01 + 0) * 0.5f;
    b[1] += *(a01 + 1) * 0.5f;
    b[2] += *(a01 + 2) * 0.5f;
    b[3] += *(a01 + 3) * 0.5f;
}
}
