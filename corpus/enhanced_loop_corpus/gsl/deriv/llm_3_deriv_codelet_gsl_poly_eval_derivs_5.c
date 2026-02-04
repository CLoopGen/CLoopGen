#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double c[];
extern  size_t lenc;
extern  double x;
extern double res[];
extern size_t i;
extern size_t nmax;
extern size_t k;
extern size_t l;
extern size_t lmax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access on 'c' array using a stride of 2 (unrolled-like pattern)
    // Process pairs of elements in reverse order with stride handling
    size_t stride = 2;
    size_t end = (lenc - 1) % stride;
    for (i = end; i < lenc - 1; i += stride) {
        k = (lenc - 1) - i;
        // Access c[k-1] as before, but now traversing with stride
        res[0] = x * res[0] + c[k - 1];
        lmax = (nmax < k) ? nmax : k - 1;
        // Inner loop remains same, but could be affected by data layout
        for (l = 1; l <= lmax; l++) {
            res[l] = x * res[l] + res[l - 1];
        }
    }
    // Handle remaining element if needed (compensate for stride)
    if ((lenc - 1) > 0 && (lenc - 1) % stride != 0) {
        i = lenc - 2;
        k = (lenc - 1) - i;
        res[0] = x * res[0] + c[k - 1];
        lmax = (nmax < k) ? nmax : k - 1;
        for (l = 1; l <= lmax; l++) {
            res[l] = x * res[l] + res[l - 1];
        }
    }
}
