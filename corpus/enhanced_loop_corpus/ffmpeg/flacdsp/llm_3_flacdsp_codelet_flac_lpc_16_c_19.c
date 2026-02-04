#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *decoded;
extern  int coeffs[32];
extern int pred_order;
extern int qlevel;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Mapping Array
    // Use an index remapping array to access `decoded` and `coeffs` indirectly
    // Simulates irregular or data-dependent access patterns
    static int idx_map[32]; // Assume max pred_order is 32
    for (int k = 0; k < pred_order; k++) {
        idx_map[k] = (k * 7) % pred_order; // Arbitrary permutation: indirect indexing
    }

    for (i = pred_order; i < len - 1; i += 2, decoded += 2) {
        unsigned int c = coeffs[idx_map[0]];
        unsigned int d = decoded[idx_map[0]];
        int s0 = 0, s1 = 0;

        for (j = 1; j < pred_order; j++) {
            s0 += c * d;
            d = decoded[idx_map[j]];
            s1 += c * d;
            c = coeffs[idx_map[j]];
        }
        s0 += c * d;
        d = decoded[idx_map[j]] += (unsigned int)(s0 >> qlevel);
        s1 += c * d;
        decoded[idx_map[j + 1]] += (unsigned int)(s1 >> qlevel);
    }
}
