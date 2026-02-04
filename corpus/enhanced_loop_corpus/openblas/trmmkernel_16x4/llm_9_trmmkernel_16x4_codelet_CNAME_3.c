#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG k;
extern float *ptrba;
extern float *ptrbb;
extern float res0_0;
extern float res0_1;
extern float res0_2;
extern float res0_3;
extern float res0_4;
extern float res0_5;
extern float res0_6;
extern float res0_7;
extern float res1_0;
extern float res1_1;
extern float res1_2;
extern float res1_3;
extern float res1_4;
extern float res1_5;
extern float res1_6;
extern float res1_7;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < temp; k++) {
    b0 = ptrbb[0];
    b1 = ptrbb[1];

    for (BLASLONG i = 0; i < 8; i++) {
        a0 = ptrba[i];
        res0_0 += a0 * b0;
        res1_0 += a0 * b1;
        if (i < 7) {
            a1 = ptrba[i + 1];
            res0_1 += a1 * b0;
            res1_1 += a1 * b1;
        }
    }

    ptrba = ptrba + 8;
    ptrbb = ptrbb + 2;
}
}
