#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii++) {
    if (ao1 == ao2 || ao3 != ao4) {
        b[0] = *ao1;
        b[1] = *ao2;
        b[2] = *ao3;
        b[3] = *ao4;
        ao1++;
        ao2++;
        ao3++;
        ao4++;
        b += 4;
    } else {
        b[0] = *ao2;
        b[1] = *ao1;
        b[2] = *ao4;
        b[3] = *ao3;
        ao1++;
        ao2++;
        ao3++;
        ao4++;
        b += 4;
    }
}
}
