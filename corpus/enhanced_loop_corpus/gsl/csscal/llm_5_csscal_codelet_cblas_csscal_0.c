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
    for (i = 0; i < N; i++) {
        float *ptr = (float *)X + 2 * ix;
        if (ix >= 0) {
            ptr[0] *= alpha;
            ptr[1] *= alpha;
        }
        ix += incX;
    }
}
