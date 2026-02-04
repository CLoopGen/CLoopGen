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
    int offset = ix;
    for (i = 0; i < N; i++) {
        x_ptr[2 * offset] *= alpha;
        x_ptr[2 * offset + 1] *= alpha;
        offset += incX;
    }
    ix = offset;
}
