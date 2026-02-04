#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern  double x;
extern double product;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern (simulated via step size in loop index)
    // Here we simulate a strided access by updating k in strides of 2, but still cover all values by handling pairs
    product = 1.0; // Reset product assuming it's part of the logic
    int step = 2;
    int i;
    for (i = 1; i <= n; i += step) {
        // Process current and next element if within bounds (unrolled-like behavior)
        product *= (x / i);
        if (i + 1 <= n) {
            product *= (x / (i + 1));
        }
    }
}
