#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double beta;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    double *Ci = &(((double *)C)[2 * (ldc * i)]);
    Ci[2 * i] *= beta;
    Ci[2 * i + 1] = 0;

    for (j = i + 1; j < N; j += 4) {
        double *Cj = &Ci[2 * j];
        Cj[0] *= beta;
        Cj[1] *= beta;

        if (j + 1 < N) {
            Cj[2] *= beta;
            Cj[3] *= beta;
        }
        if (j + 2 < N) {
            Cj[4] *= beta;
            Cj[5] *= beta;
        }
        if (j + 3 < N) {
            Cj[6] *= beta;
            Cj[7] *= beta;
        }
    }
}
}
