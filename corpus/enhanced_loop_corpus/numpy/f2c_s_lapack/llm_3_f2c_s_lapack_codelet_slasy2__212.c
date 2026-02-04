#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer i__;
extern integer j;
extern integer k;
extern real t16[16];
extern real tmp[4];
extern real btmp[4];
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reverse iteration with consecutive memory writes to tmp
for (i__ = 3; i__ >= 0; --i__) {
    k = i__ + 1;
    int idx_k = k - 1;
    int base_t16 = k - 1 + (k << 2); // Precompute base index for t16[k][k]
    temp = 1.F / t16[base_t16 - 5];
    
    // Force sequential write pattern in tmp by reversing computation order
    tmp[i__] = btmp[idx_k] * temp;

    // Inner loop accesses t16 with regular stride but traverses forward
    for (j = k + 1; j <= 4; ++j) {
        int col_idx = j - 1; // map j to 0-based index
        tmp[i__] -= temp * t16[k - 1 + (j << 2) - 5] * tmp[col_idx];
    }
}
}
