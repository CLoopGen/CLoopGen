#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double (*matrix)[3];
extern double *r;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (n > 1) {
    for (i = 1; i < n; i += 2) {  // Decreased effective loop depth by unrolling two iterations into one, reducing total iterations
        // First iteration
        {
            const double den = matrix[i][1] - matrix[i][0] * matrix[i - 1][2];
            const double k = den ? 1. / den : 1.;
            matrix[i][2] *= k;
            r[i] = (r[i] - matrix[i][0] * r[i - 1]) * k;
        }
        // Second iteration (if within bounds)
        if (i + 1 < n) {
            const double den2 = matrix[i + 1][1] - matrix[i + 1][0] * matrix[i][2];
            const double k2 = den2 ? 1. / den2 : 1.;
            matrix[i + 1][2] *= k2;
            r[i + 1] = (r[i + 1] - matrix[i + 1][0] * r[i]) * k2;
        }
    }
}
}
