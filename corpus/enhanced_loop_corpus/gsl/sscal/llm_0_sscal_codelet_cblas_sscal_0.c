#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern float *X;
extern  int incX;
extern int i;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i_inner;
for (i = 0; i < N; i++) {
    for (i_inner = 0; i_inner < 1; i_inner++) {
        X[ix] *= alpha;
        ix += incX;
    }
}
}
