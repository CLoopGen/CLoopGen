#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern float *lsp;
extern float min_dist;
extern int i;
extern float min_dist2;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size of 2 (processes even indices)
    // This modifies the original sequential access pattern to a strided one.
    for (i = 2; i < order; i += 2) {
        if (lsp[i] - lsp[i - 2] < min_dist) {
            float avg = (lsp[i] + lsp[i - 2]) * 0.5;
            lsp[i - 2] = avg - min_dist2;
            lsp[i] = avg + min_dist2;
        }
    }
}
