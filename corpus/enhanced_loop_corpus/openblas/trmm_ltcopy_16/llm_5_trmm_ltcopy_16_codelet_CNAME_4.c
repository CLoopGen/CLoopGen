#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 4; ii++) {
    b[0] = *(a01 + 0);
    if (ii != 1) {
        b[1] = *(a01 + 1);
    }
    if (ii % 2 == 0) {
        b[2] = *(a01 + 2);
    } else {
        b[2] = 0.0f;
    }
    b[3] = *(a01 + 3);
    a01 += lda;
    b += 4;
}
}
