#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

double *moment;
double cheb12[13];
double res12_cos;
double res12_sin;
size_t i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB of data (each double is 8 bytes)
    
    // Allocate moment array with sufficient size to avoid out-of-bounds access
    // Maximum index accessed: k+1 where k = 10 - 2*i, i from 0 to 5 -> max k+1 = 11
    // So we need at least 12 elements, but allocate more for larger data footprint
    moment = (double*)aligned_alloc(32, data_size * sizeof(double));
    
    if (!moment) {
        exit(1);
    }
    
    // Initialize all moment values to prevent undefined behavior
    for (size_t idx = 0; idx < data_size; idx++) {
        moment[idx] = (double)(idx % 1000) / 100.0;
    }
    
    // Initialize cheb12 array (13 elements as declared)
    for (int idx = 0; idx < 13; idx++) {
        cheb12[idx] = (double)(idx + 1) / 10.0;
    }
    
    // Initialize accumulators
    res12_cos = 0.0;
    res12_sin = 0.0;
    i = 0;
}