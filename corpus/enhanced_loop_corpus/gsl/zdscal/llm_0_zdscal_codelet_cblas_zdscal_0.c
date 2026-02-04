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
    for (int k = 0; k < N; k++) {
        for (i = 0; i < 1; i++) {
            (((double *)X)[2 * (ix)]) *= alpha;
            (((double *)X)[2 * (ix) + 1]) *= alpha;
            ix += incX;
        }
    }
}
