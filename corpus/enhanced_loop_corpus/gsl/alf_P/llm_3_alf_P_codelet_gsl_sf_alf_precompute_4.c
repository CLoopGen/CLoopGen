#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t lmax;
extern  size_t mmax;
extern double *alm;
extern double *sqrts;
extern size_t l;
extern size_t m;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification - Strided Access with Index Vectorization Emulation
    // Simulate wider memory strides by precomputing frequently used indices and accessing in batch-like fashion
    for (m = 0; m <= mmax; ++m) {
        if (m > 0) {
            k += 2;
        }
        for (l = m + 2; l <= lmax; ++l) {
            // Precompute common subexpressions and access strided data in a structured way
            size_t base_sqrts_idx = 2 * l - 3;
            const double *base = &sqrts[base_sqrts_idx];
            
            double r1 = base[4] / sqrts[l + m];     // sqrts[2*l+1] / sqrts[l+m]
            double r2 = base[2] / sqrts[l - m];     // sqrts[2*l-1] / sqrts[l-m]
            alm[2 * k] = r1 * r2;
            
            double r3 = sqrts[l + m - 1] / sqrts[l + m];
            double r4 = sqrts[l - m - 1] / sqrts[l - m];
            double r5 = base[4] / base[0];          // sqrts[2*l+1] / sqrts[2*l-3]
            alm[2 * k + 1] = -(r3 * r4 * r5);
            
            ++k;
        }
    }
}
