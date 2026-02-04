#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *dst;
extern  int32_t *src0;
extern  int32_t *src1;
extern  int32_t *win;
extern int len;
extern int32_t s0;
extern int32_t s1;
extern int32_t wi;
extern int32_t wj;
extern int32_t i;
extern int32_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with reversed indexing (unrolled-like pattern)
    // Instead of accessing src0[i], src1[j], etc., we reorganize the loop to access consecutive elements
    // in forward order for better cache locality, by precomputing indices.
    int32_t *d = dst;
    const int32_t *s0_ptr = src0;
    const int32_t *s1_ptr = src1;
    const int32_t *w = win;
    int idx_i, idx_j;

    for (i = 0; i < len; i++) {
        idx_i = i - len;          // maps to original i = -len, ..., -1
        idx_j = len - 1 - i;      // maps to original j = len-1, ..., 0

        s0 = s0_ptr[idx_i];
        s1 = s1_ptr[idx_j];
        wi = w[idx_i];
        wj = w[idx_j];

        d[idx_i] = ((int64_t)s0 * wj - (int64_t)s1 * wi + 1073741824) >> 31;
        d[idx_j] = ((int64_t)s0 * wi + (int64_t)s1 * wj + 1073741824) >> 31;
    }
}
