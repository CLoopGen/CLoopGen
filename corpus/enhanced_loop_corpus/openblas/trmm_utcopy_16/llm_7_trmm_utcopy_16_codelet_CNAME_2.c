#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 8; ii++) {
        b[0] = *(a01 + 0);
        *(a01 + 1) = b[1]; // Introduce WAR dependency: write after read from b[1]
        b[2] = *(a01 + 2);
        *(a01 + 3) = b[3]; // Another WAR
        b[4] = *(a01 + 4);
        *(a01 + 5) = b[5];
        b[6] = *(a01 + 6);
        *(a01 + 7) = b[7];
        a01 += lda;
        b += 8;
    }
}
