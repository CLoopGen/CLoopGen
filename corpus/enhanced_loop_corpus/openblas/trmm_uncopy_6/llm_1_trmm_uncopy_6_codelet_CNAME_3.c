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
    if (i > 0) {
        for (ii = 0; ii < i; ii++) {
            for (BLASLONG inner = 0; inner < 1; inner++) {
                b[0] = *(ao1 + 0);
                b[1] = *(ao2 + 0);
                b[2] = *(ao3 + 0);
                b[3] = *(ao4 + 0);
                ao1++;
                ao2++;
                ao3++;
                ao4++;
                b += 4;
            }
        }
    }
}
