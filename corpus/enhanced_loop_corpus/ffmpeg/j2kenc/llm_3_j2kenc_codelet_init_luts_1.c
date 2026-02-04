#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int lut_nmsedec_ref[128];
extern int lut_nmsedec_ref0[128];
extern int lut_nmsedec_sig[128];
extern int lut_nmsedec_sig0[128];
extern int i;
extern int a;
extern int mask;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access with reverse traversal
    // This variant accesses arrays with a negative stride (reverse order) and uses indirect indexing
    // through a precomputed index array to simulate non-sequential access patterns.

    int index_map[128];
    for (i = 0; i < (1 << 7); i++) {
        index_map[i] = (1 << 7) - 1 - i;  // Reverse mapping: last element first
    }

    for (i = 0; i < (1 << 7); i++) {
        int idx = index_map[i];  // Indirect access via reversed index

        lut_nmsedec_sig[idx] = (((3 * idx << (13 - (7 - 1))) - (9 << 11)) > 0 ? 
                               ((3 * idx << (13 - (7 - 1))) - (9 << 11)) : 0);
        lut_nmsedec_sig0[idx] = (((idx * idx + (1 << (7 - 1) - 1) & mask) << 1) > 0 ? 
                                ((idx * idx + (1 << (7 - 1) - 1) & mask) << 1) : 0);
        a = (idx >> (7 - 2) & 2) + 1;
        lut_nmsedec_ref[idx] = (((a - 2) * (idx << (13 - (7 - 1))) + (1 << 13) - (a * a << 11)) > 0 ? 
                               ((a - 2) * (idx << (13 - (7 - 1))) + (1 << 13) - (a * a << 11)) : 0);
        lut_nmsedec_ref0[idx] = ((((idx * idx - (idx << 7) + (1 << 2 * (7 - 1)) + (1 << ((7 - 1) - 1))) & mask) << 1) > 0 ? 
                                (((idx * idx - (idx << 7) + (1 << 2 * (7 - 1)) + (1 << ((7 - 1) - 1))) & mask) << 1) : 0);
    }
}
