#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t order;
extern size_t i;
extern  double beta;
extern double q[11];
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Flattened loop structure: reduce nesting by merging logic into a single loop
    for (k = 1; k <= order; ++k) {
        double qm1 = q[0];
        q[0] = q[1];
        i = 1;
        for (; i <= k; ++i) {
            double tmp = q[i];
            q[i] = (i + 1.) * q[i + 1] + 2. * beta * qm1;
            qm1 = tmp;
        }
    }
    // Note: This variant keeps the same logic but emphasizes reduced nesting potential.
    // No additional inner loops; structure is already minimal, so we avoid artificial flattening that would break semantics.
    // Instead, we ensure clarity in the existing two-level nest, acknowledging that full removal of inner loop
    // would require algorithmic changes beyond structural mutation.
}
