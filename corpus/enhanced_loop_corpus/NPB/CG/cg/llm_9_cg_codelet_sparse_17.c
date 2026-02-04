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
    // Variant 2: Reduced computational intensity by merging conditions and minimizing memory writes
    // Also reduced effective trip count by skipping zero-affecting updates
    for (j = 1; j <= nrows; j++) {
        nzrow = 0;
        for (k = jajp1; k < rowstr[j + 1]; k++) {
            i = colidx[k];
            // Skip update if a[k] is zero (reduces effective work)
            if (a[k] != 0.0) {
                x[i] = x[i] + a[k];
                // Merged condition to reduce branching overhead
                if ((mark[i] == 0) & (x[i] != 0.)) {  // Bitwise AND to avoid short-circuit overhead
                    mark[i] = 1;
                    nzloc[++nzrow] = i; // Pre-increment to combine assignment and increment
                }
            }
        }

        // Compact second loop: eliminate temporary variable unless necessary
        for (k = 1; k <= nzrow; k++) {
            i = nzloc[k];
            mark[i] = 0;
            // Only read x[i] once and avoid redundant zeroing if already zero
            if (x[i] != 0.) {
                nza++;
                a[nza] = x[i];
                colidx[nza] = i;
                x[i] = 0.; // Zero only after use
            } else {
                x[i] = 0.; // Ensure reset even if zero
            }
        }

        jajp1 = rowstr[j + 1];
        rowstr[j + 1] = nza + rowstr[1];
    }
}
