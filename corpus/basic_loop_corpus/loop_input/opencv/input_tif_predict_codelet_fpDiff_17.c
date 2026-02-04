#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int tmsize_t;

tmsize_t cc;
tmsize_t stride;
tmsize_t count;

void init_vars() {
    // Set problem size to ensure loop runs for ~0.01 seconds
    // The inner loop does (stride - 4) iterations but is empty, so execution time is minimal.
    // To make outer loop run long enough, we set cc large and stride small.

    stride = 4;        // Ensures the switch jumps to case 4, avoiding negative loop bounds
    cc = 2500000;      // This makes outer loop run about (cc / stride) = 625000 iterations
    count = cc;        // Will be decremented by stride in loop
}

void loop();  // forward declaration

// Ensure linkage with external loop function
// All necessary variables are defined at file scope and initialized via init_vars