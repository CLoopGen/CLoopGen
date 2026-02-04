#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double eps;
extern int q;
extern double eqq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use indirect access via an index mapping array to simulate irregular memory access
    // We precompute an access pattern and follow it to update eqq in a reordered manner
    const int max_iter = 500;
    int indices[max_iter];
    // Create an indirect access order: reverse mapping
    for (int i = 0; i < max_iter; i++) {
        indices[i] = max_iter - 1 - i;
    }
    // Reuse q as counter but follow indirect order for logic influence (simulated effect)
    // Note: since eqq is scalar and stateful, we cannot truly reorder iterations without changing math,
    // so instead we simulate memory-like indirect tracking by saving values in reverse index order.
    double trace[max_iter];
    q = 1;
    for (int step = 0; step < max_iter && eqq > eps; step++) {
        int mapped_q = indices[step] + 1; // Mapped logical iteration
        eqq /= 16. * (2. * mapped_q + 1.) * (2. * mapped_q + 3.);
        trace[indices[step]] = eqq; // Indirect (reverse-order) storage
        q = mapped_q;
    }
}
