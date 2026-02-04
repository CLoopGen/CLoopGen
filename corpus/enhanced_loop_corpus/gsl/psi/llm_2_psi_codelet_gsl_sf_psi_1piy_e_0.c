#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double y;
extern  int M;
extern double sum;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern (simulated via step increment)
    // Although no array is present, we simulate strided iteration by stepping through indices with a fixed stride
    int stride = 2;
    int n_local;
    double local_sum = sum;

    // Process even strides first, then odd if needed to cover all values
    for (n_local = 1; n_local <= M; n_local += stride) {
        local_sum += 1. / (n_local * (n_local * n_local + y * y));
    }
    for (n_local = 2; n_local <= M; n_local += stride) {
        local_sum += 1. / (n_local * (n_local * n_local + y * y));
    }
    sum = local_sum;
}
