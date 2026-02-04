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
    // Variant 1: Consecutive memory access with reversed traversal and direct indexing
    for (i = lenc - 2; ; i--) {
        k = i + 1;
        res[0] = x * res[0] + c[i];
        lmax = (nmax < k) ? nmax : k - 1;
        for (l = 1; l <= lmax; l++) {
            res[l] = x * res[l] + res[l - 1];
        }
        if (i == 0) break;
    }
}
