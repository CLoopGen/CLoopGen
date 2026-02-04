#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern void *X;
extern  int incX;
extern int i;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *x_ptr = (float *)X;
    for (i = 0; i < N; i++) {
        float temp1 = x_ptr[2 * ix];
        float temp2 = x_ptr[2 * ix + 1];
        temp1 *= alpha;
        temp2 *= alpha;
        x_ptr[2 * ix] = temp1;
        x_ptr[2 * ix + 1] = temp2;
        ix += incX;
    }
}
