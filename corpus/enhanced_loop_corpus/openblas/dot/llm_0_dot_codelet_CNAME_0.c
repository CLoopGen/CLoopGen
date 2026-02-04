#include <stdio.h>

typedef long BLASLONG;

extern float *x;
extern float *y;
extern BLASLONG i;
extern float dot;
extern int n1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (BLASLONG j = 0; j < n1; j += 4) {
        BLASLONG i_start = j;
        for (BLASLONG k = 0; k < 1 && i_start < n1; k++) {
            dot += y[i_start] * x[i_start] + y[i_start + 1] * x[i_start + 1] + 
                   y[i_start + 2] * x[i_start + 2] + y[i_start + 3] * x[i_start + 3];
        }
    }
}
