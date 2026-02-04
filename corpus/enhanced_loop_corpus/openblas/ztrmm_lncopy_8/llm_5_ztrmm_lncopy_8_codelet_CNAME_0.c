#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;
extern float *ao5;
extern float *ao6;
extern float *ao7;
extern float *ao8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *local_b = b;
    BLASLONG offset = 0;

    for (ii = 0; ii < 8; ii++) {
        *(local_b + offset + 0)  = ao1[0];
        *(local_b + offset + 1)  = ao1[1];
        *(local_b + offset + 2)  = ao2[0];
        *(local_b + offset + 3)  = ao2[1];
        *(local_b + offset + 4)  = ao3[0];
        *(local_b + offset + 5)  = ao3[1];
        *(local_b + offset + 6)  = ao4[0];
        *(local_b + offset + 7)  = ao4[1];
        *(local_b + offset + 8)  = ao5[0];
        *(local_b + offset + 9)  = ao5[1];
        *(local_b + offset + 10) = ao6[0];
        *(local_b + offset + 11) = ao6[1];
        *(local_b + offset + 12) = ao7[0];
        *(local_b + offset + 13) = ao7[1];
        *(local_b + offset + 14) = ao8[0];
        *(local_b + offset + 15) = ao8[1];

        ao1 += 2;
        ao2 += 2;
        ao3 += 2;
        ao4 += 2;
        ao5 += 2;
        ao6 += 2;
        ao7 += 2;
        ao8 += 2;
        offset += 16;
    }

    b += 128; // Update global b after loop: 8 iterations × 16 elements
}
