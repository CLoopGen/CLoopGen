#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern void *X;
extern  int incX;
extern int i;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        double *px = (double *)X;
        size_t offset = 2 * ix;
        if (px[offset] != 0.0 || px[offset + 1] != 0.0) {
            px[offset] *= alpha;
            px[offset + 1] *= alpha;
        }
        ix += incX;
    }
}
