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
    // Variant 1: Consecutive Memory Access Pattern
    // Reorder operations to access arrays with more sequential memory access.
    // Here, we assume that arow and aelt are accessed in increasing order of nza,
    // so we keep the loop structure but reorganize computations to promote cache locality.
    int j_val, k_val;
    for (nza = 1; nza <= nnza; nza++) {
        j_val = arow[nza] - firstrow + 1;
        k_val = rowstr[j_val];
        // Sequential updates: write directly using computed indices
        a[k_val] = aelt[nza];
        colidx[k_val] = acol[nza];
        rowstr[j_val] = k_val + 1;  // update rowstr after use
    }
}
