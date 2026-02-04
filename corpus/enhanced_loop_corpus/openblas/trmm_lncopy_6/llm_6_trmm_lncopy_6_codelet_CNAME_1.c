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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG temp_i = i;
float *temp_b = b;
for (ii = 0; ii < temp_i; ii++) {
    temp_b[0] = ao1[0];
    temp_b[1] = ao2[0];
    temp_b[2] = ao3[0];
    temp_b[3] = ao4[0];
    temp_b[4] = ao5[0];
    temp_b[5] = ao6[0];
    // Introduce artificial loop-carried dependency via pointer update chaining
    ao1 = ao1 + 1;
    ao2 = ao1 + (ao2 - &ao2[0]); // WAR-like dependency: ao2 base depends on updated ao1
    ao3 = ao2 + (ao3 - &ao3[0]);
    ao4 = ao3 + (ao4 - &ao4[0]);
    ao5 = ao4 + (ao5 - &ao5[0]);
    ao6 = ao5 + (ao6 - &ao6[0]);
    temp_b += 6;
}
}
