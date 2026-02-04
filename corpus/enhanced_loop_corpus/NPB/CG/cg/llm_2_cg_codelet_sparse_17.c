#include <stdio.h>

typedef int boolean;

extern double a[];
extern int colidx[];
extern int rowstr[];
extern double x[];
extern boolean mark[];
extern int nzloc[];
extern int nrows;
extern int i;
extern int j;
extern int jajp1;
extern int nza;
extern int k;
extern int nzrow;
extern double xi;



void loop(){
    // Variant 1: Memory Access Pattern Modification - Use strided access with step size 2 (unroll by factor of 2)
    // This variant processes two elements at a time in the inner loops to promote better cache utilization
    // and reduce loop overhead, assuming data alignment allows safe unrolling.

    for (j = 1; j <= nrows; j++) {
        nzrow = 0;
        int start_k = jajp1;
        int end_k = rowstr[j + 1];

        // Unroll the first loop by factor of 2 for strided memory access pattern
        int k = start_k;
        int limit = end_k - 1;
        for (; k < limit; k += 2) {
            int i1 = colidx[k];
            int i2 = colidx[k + 1];

            x[i1] = x[i1] + a[k];
            x[i2] = x[i2] + a[k + 1];

            if (mark[i1] == 0 && x[i1] != 0.) {
                mark[i1] = 1;
                nzrow = nzrow + 1;
                nzloc[nzrow] = i1;
            }
            if (mark[i2] == 0 && x[i2] != 0.) {
                mark[i2] = 1;
                nzrow = nzrow + 1;
                nzloc[nzrow] = i2;
            }
        }
        // Handle remaining element if any
        for (; k < end_k; k++) {
            i = colidx[k];
            x[i] = x[i] + a[k];
            if (mark[i] == 0 && x[i] != 0.) {
                mark[i] = 1;
                nzrow = nzrow + 1;
                nzloc[nzrow] = i;
            }
        }

        // Process nzloc array with consecutive indexing
        for (k = 1; k <= nzrow; k++) {
            i = nzloc[k];
            mark[i] = 0;
            xi = x[i];
            x[i] = 0.;
            if (xi != 0.) {
                nza = nza + 1;
                a[nza] = xi;
                colidx[nza] = i;
            }
        }
        jajp1 = rowstr[j + 1];
        rowstr[j + 1] = nza + rowstr[1];
    }
}
