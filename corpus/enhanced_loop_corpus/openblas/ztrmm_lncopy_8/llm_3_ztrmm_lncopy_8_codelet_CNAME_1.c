#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
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
for (ii = 0; ii < i; ii++) {
    BLASLONG idx = ii * 16;
    BLASLONG step_a = 2 * ii;

    // Interleaved strided write pattern: store even indices first, then odd
    b[idx + 0]  = ao1[step_a];
    b[idx + 2]  = ao1[step_a + 1];
    b[idx + 4]  = ao2[step_a];
    b[idx + 6]  = ao2[step_a + 1];
    b[idx + 8]  = ao3[step_a];
    b[idx + 10] = ao3[step_a + 1];
    b[idx + 12] = ao4[step_a];
    b[idx + 14] = ao4[step_a + 1];

    b[idx + 1]  = ao5[step_a];
    b[idx + 3]  = ao5[step_a + 1];
    b[idx + 5]  = ao6[step_a];
    b[idx + 7]  = ao6[step_a + 1];
    b[idx + 9]  = ao7[step_a];
    b[idx + 11] = ao7[step_a + 1];
    b[idx + 13] = ao8[step_a];
    b[idx + 15] = ao8[step_a + 1];
}
}
