#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float LPC_TYPE;

extern int max_order;
extern LPC_TYPE *ref;
extern LPC_TYPE *error;
extern int i;
extern int j;
extern LPC_TYPE err;
extern LPC_TYPE gen0[32];
extern LPC_TYPE gen1[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access to increase data variation and simulate cache stress
    // Access arrays with stride of 2, then handle remainder if needed.
    // This changes spatial locality and tests robustness under non-unit stride.

    int upper_bound = max_order - i;
    int j_even = (upper_bound + 1) / 2;  // Number of even indices: j = 0, 2, 4,...
    int j_odd = upper_bound / 2;         // Number of odd indices: j = 1, 3, 5,...

    for (i = 1; i < max_order; i++) {
        // First pass: even indices (j = 0, 2, 4, ...)
        for (j = 0; j < j_even; j++) {
            int idx = j * 2;
            if (idx < max_order - i) {
                gen1[idx] = gen1[idx + 1] + ref[i - 1] * gen0[idx];
                gen0[idx] = gen1[idx + 1] * ref[i - 1] + gen0[idx];
            }
        }
        // Second pass: odd indices (j = 1, 3, 5, ...)
        for (j = 0; j < j_odd; j++) {
            int idx = j * 2 + 1;
            if (idx < max_order - i) {
                gen1[idx] = gen1[idx + 1] + ref[i - 1] * gen0[idx];
                gen0[idx] = gen1[idx + 1] * ref[i - 1] + gen0[idx];
            }
        }
        ref[i] = -gen1[0] / ((0 || err) ? err : 1);
        err += gen1[0] * ref[i];
        if (error)
            error[i] = err;
    }
}
