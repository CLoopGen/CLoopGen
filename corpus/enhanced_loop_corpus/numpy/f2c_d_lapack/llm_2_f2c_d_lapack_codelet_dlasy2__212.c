#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer i__;
extern integer j;
extern integer k;
extern doublereal t16[16];
extern doublereal tmp[4];
extern doublereal btmp[4];
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access Pattern
    // Reformulate indexing to access t16 and tmp in a more sequential manner by precomputing base indices.
    for (i__ = 1; i__ <= 4; ++i__) {
        k = 5 - i__;
        integer base_k = k - 1;  // 0-based index for tmp and btmp
        integer offset_k = k + (k << 2) - 5;  // Original t16 index: k + 5*k - 5 = 6*k - 5
        temp = 1. / t16[offset_k];
        tmp[base_k] = btmp[base_k] * temp;
        for (j = k + 1; j <= 4; ++j) {
            integer offset_t = k + (j << 2) - 5;  // t16[k + 5*j - 5]
            tmp[base_k] -= temp * t16[offset_t] * tmp[j - 1];
        }
    }
}
