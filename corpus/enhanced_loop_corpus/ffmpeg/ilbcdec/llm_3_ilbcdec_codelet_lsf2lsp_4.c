#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t cos_tbl[64];
extern  int16_t cos_derivative_tbl[64];
extern int16_t *lsf;
extern int16_t *lsp;
extern int order;
extern int16_t diff;
extern int16_t freq;
extern int32_t tmp;
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (Indexed) Memory Access Pattern
    // Use an index array to access lsf, and indirectly determine lookup into cos tables
    // Simulate indirect access via precomputed indices (e.g., like gathered loads)
    // Assume we have an auxiliary index mapping: map[i] = some permutation or reordering
    static int map[64]; // Assume max order is 64 as per table size
    if (map[0] == 0) { // Initialize once (minimal overhead assumption)
        for (int idx = 0; idx < 64; idx++) {
            map[idx] = idx; // Identity permutation initially; could be randomized in real use cases
        }
    }

    for (i = 0; i < order; i++) {
        int idx = map[i]; // Indirect access through index map
        freq = (lsf[idx] * 20861) >> 15;
        k = ((freq >> 8) > 63 ? 63 : (freq >> 8));
        diff = freq & 255;
        tmp = cos_derivative_tbl[k] * diff;
        lsp[idx] = cos_tbl[k] + (tmp >> 12); // Write back using same indirect index
    }
}
