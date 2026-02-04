#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    // Eliminate some intra-iteration dependencies by precomputing independent values
    int x0 = coef[i * 4 + 0];
    int x1 = coef[i * 4 + 1];
    int x2 = coef[i * 4 + 2];
    int x3 = coef[i * 4 + 3];
    // Break chain of computation: compute all outputs in parallel relative to inputs
    int sum_ab = x0 + x1;
    int diff_dc = x3 - x2;
    int e1 = (sum_ab - diff_dc) >> 1;
    int out_a1 = (sum_ab - (e1 - x2)) * 2;
    int out_c1 = (e1 - x2) * 2;
    int out_d1 = (diff_dc + (e1 - x1)) * 2;
    int out_b1 = (e1 - x1) * 2;
    // Remove write-after-write by storing only once, all values derived directly from original loads
    // This reduces WAW and WAR hazards within the iteration
    coef[i * 4 + 0] = out_a1;
    coef[i * 4 + 1] = out_c1;
    coef[i * 4 + 2] = out_d1;
    coef[i * 4 + 3] = out_b1;
}
}
