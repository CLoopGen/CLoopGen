#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp1, temp2, temp3, temp4;
    for (ii = 0; ii < 4; ii++) {
        temp1 = *(ao1 + 0);
        temp2 = *(ao1 + 1);
        b[0] = temp1;
        b[1] = temp2;

        temp1 = *(ao2 + 0);
        temp2 = *(ao2 + 1);
        b[2] = temp1;
        b[3] = temp2;

        temp3 = *(ao3 + 0);
        temp4 = *(ao3 + 1);
        b[4] = temp3;
        b[5] = temp4;

        temp3 = *(ao4 + 0);
        temp4 = *(ao4 + 1);
        b[6] = temp3;
        b[7] = temp4;

        ao1 += 2;
        ao2 += 2;
        ao3 += 2;
        ao4 += 2;
        b += 8;
    }
}
