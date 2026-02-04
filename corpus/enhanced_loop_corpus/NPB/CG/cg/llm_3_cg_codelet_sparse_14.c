#include <stdio.h>

extern double a[];
extern int colidx[];
extern int rowstr[];
extern int arow[];
extern int acol[];
extern double aelt[];
extern int firstrow;
extern int nnza;
extern int j;
extern int nza;
extern int k;



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Introduce a strided traversal over the iteration space to simulate non-unit stride access.
    // This variant processes every second element forward and backward to create strided patterns.
    int stride = 2;
    int nza_forward, nza_backward;

    // Forward strided pass
    for (nza_forward = 1; nza_forward <= nnza; nza_forward += stride) {
        j = arow[nza_forward] - firstrow + 1;
        k = rowstr[j];
        a[k] = aelt[nza_forward];
        colidx[k] = acol[nza_forward];
        rowstr[j] = k + 1;
    }

    // Backward strided pass for remaining or overlapping pattern (simulate reverse strided access)
    for (nza_backward = nnza - ((nnza - 1) % stride); nza_backward >= 1; nza_backward -= stride) {
        if (nza_backward % stride == 1 && nza_backward != 1) continue; // avoid duplicate work when stride > 1
        j = arow[nza_backward] - firstrow + 1;
        k = rowstr[j];
        a[k] = aelt[nza_backward];
        colidx[k] = acol[nza_backward];
        rowstr[j] = k + 1;
    }
}
