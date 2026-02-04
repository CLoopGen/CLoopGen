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
    // Variant 1: Increased computational intensity by unrolling the inner loops and adding redundant arithmetic operations
    // Also modified trip count by processing two elements per iteration in the first inner loop
    for (j = 1; j <= nrows; j++) {
        nzrow = 0;
        int k_start = jajp1;
        int k_end = rowstr[j + 1];
        // Loop unrolling by factor of 2 with added arithmetic overhead
        for (k = k_start; k < k_end - 1; k += 2) {
            // Process two elements
            i = colidx[k];
            x[i] = x[i] + a[k] + 0.0; // Redundant addition to increase computation
            if (mark[i] == 0 && x[i] != 0.) {
                mark[i] = 1;
                nzrow = nzrow + 1;
                nzloc[nzrow] = i;
            }

            i = colidx[k + 1];
            x[i] = x[i] + a[k + 1] + 0.0;
            if (mark[i] == 0 && x[i] != 0.) {
                mark[i] = 1;
                nzrow = nzrow + 1;
                nzloc[nzrow] = i;
            }
        }
        // Handle remaining element if any
        if (k < k_end) {
            i = colidx[k];
            x[i] = x[i] + a[k] + 0.0;
            if (mark[i] == 0 && x[i] != 0.) {
                mark[i] = 1;
                nzrow = nzrow + 1;
                nzloc[nzrow] = i;
            }
        }

        // Second loop: increased arithmetic by introducing dummy variable and extra assignment
        double temp_sum = 0.0;
        for (k = 1; k <= nzrow; k++) {
            i = nzloc[k];
            mark[i] = 0;
            xi = x[i];
            temp_sum += xi * xi; // Extra computation
            x[i] = 0.;
            if (xi != 0.) {
                nza = nza + 1;
                a[nza] = xi;
                colidx[nza] = i;
            }
        }
        // Dummy use of temp_sum to prevent optimization
        if (temp_sum > 0.0) {
            temp_sum = temp_sum + 0.0;
        }

        jajp1 = rowstr[j + 1];
        rowstr[j + 1] = nza + rowstr[1];
    }
}
