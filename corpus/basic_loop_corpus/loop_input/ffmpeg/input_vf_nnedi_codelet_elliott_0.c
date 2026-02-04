#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

float *data;
int n = 0;
int i = 0;

void init_vars() {
    const double target_time = 0.01; 
    const double ops_per_byte = 1.0;  
    const double estimated_gflops = 5.0; 
    const size_t bytes_per_op = sizeof(float);
    
    size_t num_elements = (size_t)(target_time * estimated_gflops * 1e9 / ops_per_byte);
    n = (int)(num_elements > INT32_MAX ? INT32_MAX : num_elements);
    if (n == 0) n = 1 << 20; 

    data = (float*)aligned_alloc(32, (size_t)n * sizeof(float));
    if (!data) {
        n = 1 << 20;
        data = (float*)aligned_alloc(32, (size_t)n * sizeof(float));
    }

    for (int idx = 0; idx < n; idx++) {
        data[idx] = (float)((rand() % 20000) - 10000) / 1000.0f; 
    }
}