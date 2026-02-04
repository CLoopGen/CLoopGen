#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern double value;
extern ssize_t i;
extern ssize_t n;
extern ssize_t order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with expanded arithmetic and reduced trip count
    // Trip count halved, but each iteration performs additional multiplicative operations
    ssize_t limit = order / 2;
    for (i = 0; i < limit; i++) {
        double diff_n_i = (double)(n - i);
        double term1 = (diff_n_i - x) / diff_n_i;
        double term2 = (diff_n_i - x - 1.0) / (diff_n_i + 1.0);
        value *= (term1 * term2 * term1);  // Additional arithmetic intensity
    }
}
