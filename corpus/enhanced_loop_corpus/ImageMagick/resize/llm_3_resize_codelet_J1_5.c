#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern double p;
extern double q;
extern ssize_t i;
extern  double Pone[];
extern  double Qone[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride 2 (wrapping around using modulo)
    // Simulates non-unit stride access pattern; uses only even indices: 6, 4, 2, 0, then repeats if needed
    // To preserve 8 iterations, we use modulo arithmetic on a strided index
    ssize_t idx;
    for (idx = 6; idx >= -8; idx -= 2) {
        ssize_t effective_idx = (idx < 0) ? (-idx - 1) % 8 : idx; // Mirror negative indices
        effective_idx = effective_idx & 7; // Ensure within bounds [0,7]
        p = p * x * x + Pone[effective_idx];
        q = q * x * x + Qone[effective_idx];
    }
}
