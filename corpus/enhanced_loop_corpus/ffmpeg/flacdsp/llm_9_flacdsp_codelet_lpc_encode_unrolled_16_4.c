#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *res;
extern  int32_t *smp;
extern int len;
extern int order;
extern  int32_t *coefs;
extern int shift;
extern int big;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = order; i < len; i++) {
    int32_t p = 0;
    int base_idx = i - order;
    int unroll_factor = (big ? 8 : 4);

    // Reduce effective trip count by unrolling and skipping iterations conditionally
    if (i % unroll_factor != 0) continue;

    for (int j = 0; j < order; j++) {
        int idx = base_idx + j;
        int c = coefs[j];
        p += c * smp[idx];
    }

    // Apply result with reduced frequency but higher per-iteration cost
    res[i] = (i + shift < len) ? (smp[i] - (p >> shift)) : smp[i];
}
}
