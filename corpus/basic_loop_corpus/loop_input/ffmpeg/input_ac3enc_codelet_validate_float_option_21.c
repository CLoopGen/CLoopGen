#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

float v;
float *v_list;
int v_list_size;
int i;

static float *generated_v_list = NULL;

void init_vars() {
    const size_t target_time_ns = 10000000; // 0.01 seconds in nanoseconds
    const double ops_per_cycle_estimate = 1.0;
    const long cpu_freq_hz = 3000000000LL; // Assume 3 GHz
    const double estimated_ops_per_iteration = 5.0;
    const size_t estimated_size = (target_time_ns * cpu_freq_hz) / (1e9 * estimated_ops_per_iteration);

    v_list_size = (int)fmax(1000, fmin(256 * 1024 * 1024 / sizeof(float), estimated_size));
    
    generated_v_list = (float *)aligned_alloc(32, (size_t)v_list_size * sizeof(float));
    if (!generated_v_list) {
        v_list_size = 1000;
        generated_v_list = (float *)calloc(v_list_size, sizeof(float));
    }

    for (int j = 0; j < v_list_size; j++) {
        generated_v_list[j] = (float)(j * 0.02);
    }

    v_list = generated_v_list;
    v = (float)(v_list_size / 2) * 0.02 + 0.005;
}