#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern int lo;
extern int hi;
extern int k;
extern double **A_me;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *Ai = A_me[i];
    double *Aj = A_me[j];
    for (k = lo; k <= hi; k++) {
        tmp = Ai[k];
        Ai[k] = Aj[k];
        Aj[k] = tmp;
    }
}
