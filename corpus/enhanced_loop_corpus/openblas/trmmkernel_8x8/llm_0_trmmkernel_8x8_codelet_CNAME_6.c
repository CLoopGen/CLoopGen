#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG k;
extern float *ptrba;
extern float *ptrbb;
extern float res0_0;
extern float res1_0;
extern float res2_0;
extern float res3_0;
extern float a0;
extern float b0;
extern float b1;
extern float b2;
extern float b3;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    BLASLONG i, j;
    for (i = 0; i < temp; i++) {
        for (j = 0; j < 1; j++) {  // Introduce inner loop with fixed iteration (depth increased)
            b0 = ptrbb[0];
            b1 = ptrbb[1];
            b2 = ptrbb[2];
            b3 = ptrbb[3];
            a0 = ptrba[0];
            res0_0 += a0 * b0;
            res1_0 += a0 * b1;
            res2_0 += a0 * b2;
            res3_0 += a0 * b3;
            ptrba = ptrba + 1;
            ptrbb = ptrbb + 4;
        }
    }
}
