#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii++) {
    for (BLASLONG k = 0; k < 4; k++) {
        b[k] = *(ao1 + k);
    }
    b += 4;
}
}
