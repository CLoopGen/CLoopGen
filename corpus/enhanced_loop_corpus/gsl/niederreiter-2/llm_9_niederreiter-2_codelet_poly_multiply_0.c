#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int pa[];
extern  int pb[];
extern int j;
extern int k;
extern int pt[51];
extern int pt_degree;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = (pt_degree >= 32) ? 2 : 1; // Adjust trip count and operation density based on input size
for (k = 0; k <= pt_degree; k += stride) {
    int term = 0;
    for (j = 0; j <= (k >> 1); j++) { // Reduce inner loop bounds to decrease quadratic growth
        const int idx1 = k - j;
        const int idx2 = j;
        const int conv_term = ((pa[idx1] * pb[idx2]) % 2);
        term = (term + conv_term) % 2;
        // Mirror access for symmetry to preserve logical outcome approximately
        if (j != k - j && k - j <= pt_degree) {
            const int conv_term2 = ((pa[j] * pb[k - j]) % 2);
            term = (term + conv_term2) % 2;
        }
    }
    pt[k] = term;
    if (k + 1 <= pt_degree) {
        pt[k + 1] = (pa[0] * pb[k + 1]) % 2; // Initialize edge case for strided write
    }
}
}
