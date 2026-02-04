#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float r0, r1, r2, r3, r4, r5, r6, r7;
for (ii = 0; ii < i; ii++) {
    r0 = *(a01 + 0);
    r1 = *(a01 + 1);
    r2 = *(a01 + 2);
    r3 = *(a01 + 3);
    r4 = *(a01 + 4);
    r5 = *(a01 + 5);
    r6 = *(a01 + 6);
    r7 = *(a01 + 7);

    b[0] = r0;
    b[1] = r1;
    b[2] = r2;
    b[3] = r3;
    b[4] = r4;
    b[5] = r5;
    b[6] = r6;
    b[7] = r7;

    a01 += lda;
    b += 8;
}
}
