#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *local_b = b;
    for (ii = 0; ii < i; ii++) {
        float temp0 = *(ao1 + 0);
        float temp1 = *(ao1 + 1);
        float temp2 = *(ao1 + 2);
        float temp3 = *(ao1 + 3);
        local_b[0] = temp0;
        local_b[1] = temp1;
        local_b[2] = temp2;
        local_b[3] = temp3;
        local_b += 4;
    }
    b = local_b;
}
