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
    // Variant 2: Memory Access Pattern Modification - Indirect access via pointer chasing
    // Instead of direct indexing into arrays like a[k], colidx[k], we simulate indirect access
    // using an auxiliary index map that reorders access sequence. This mimics irregular memory patterns
    // such as those found in sparse matrix computations with permutation.

    // Create a local static-like index remapping (for demonstration, use simple reverse within segment)
    // Note: In practice, this could be a precomputed permutation; here we simulate on-the-fly

    for (j = 1; j <= nrows; j++) {
        nzrow = 0;
        int start_k = jajp1;
        int count_k = rowstr[j + 1] - start_k;

        // Build virtual index map: reverse access order (indirect traversal)
        for (int offset = 0; offset < count_k; offset++) {
            int k = start_k + offset;
            int mapped_k = start_k + (count_k - 1 - offset); // reverse mapping

            i = colidx[mapped_k];
            x[i] = x[i] + a[mapped_k];
            if (mark[i] == 0 && x[i] != 0.) {
                mark[i] = 1;
                nzrow = nzrow + 1;
                nzloc[nzrow] = i;
            }
        }

        // Second loop remains logically same but preserves indirect effect from prior phase
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
