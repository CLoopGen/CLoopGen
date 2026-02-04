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
    for (ii = 0; ii < i; ii += 2) {
        if (ii + 1 < i) {
            // Process two iterations at once to increase computational intensity
            float temp1_0 = *(ao1 + 0);
            float temp2_0 = *(ao2 + 0);
            float temp3_0 = *(ao3 + 0);
            float temp4_0 = *(ao4 + 0);
            ao1++; ao2++; ao3++; ao4++;

            float temp1_1 = *(ao1 + 0);
            float temp2_1 = *(ao2 + 0);
            float temp3_1 = *(ao3 + 0);
            float temp4_1 = *(ao4 + 0);

            b[0] = temp1_0;
            b[1] = temp2_0;
            b[2] = temp3_0;
            b[3] = temp4_0;
            b[4] = temp1_1;
            b[5] = temp2_1;
            b[6] = temp3_1;
            b[7] = temp4_1;

            ao1++; ao2++; ao3++; ao4++;
            b += 8;
        } else {
            // Handle leftover iteration
            b[0] = *(ao1 + 0);
            b[1] = *(ao2 + 0);
            b[2] = *(ao3 + 0);
            b[3] = *(ao4 + 0);
            ao1++; ao2++; ao3++; ao4++;
            b += 4;
        }
    }
}
