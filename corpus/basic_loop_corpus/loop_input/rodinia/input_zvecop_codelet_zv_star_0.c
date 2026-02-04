#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef struct {
    double re;
    double im;
} complex;

typedef struct {
    u_int dim;
    u_int max_dim;
    complex *ve;
} ZVEC;

complex *x1_ve;
complex *x2_ve;
complex *out_ve;

ZVEC x1_data;
ZVEC x2_data;
ZVEC out_data;

ZVEC *x1 = &x1_data;
ZVEC *x2 = &x2_data;
ZVEC *out = &out_data;

int i;
double t_re;
double t_im;

void init_vars() {
    const long target_time_ns = 10000000; // 10 ms in nanoseconds
    const long base_size = 1 << 18; // Start with ~1M elements
    const double est_ops_per_element = 8.0; // Rough estimate of FP operations per element
    const double cpu_freq_gflops = 3.0; // Assume 3 GFLOPS effective rate
    
    // Estimate number of elements to run for ~10ms
    long num_elements = (long)((target_time_ns / 1e9) * cpu_freq_gflops * 1e9 / est_ops_per_element);
    num_elements = num_elements < base_size ? base_size : num_elements;
    num_elements = num_elements > (1 << 28) ? (1 << 28) : num_elements; // Cap at ~256M elements

    x1_ve = (complex*)aligned_alloc(32, num_elements * sizeof(complex));
    x2_ve = (complex*)aligned_alloc(32, num_elements * sizeof(complex));
    out_ve = (complex*)aligned_alloc(32, num_elements * sizeof(complex));

    if (!x1_ve || !x2_ve || !out_ve) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (long j = 0; j < num_elements; j++) {
        x1_ve[j].re = (double)(j % 100) * 0.1;
        x1_ve[j].im = (double)((j + 10) % 100) * 0.1;
        x2_ve[j].re = (double)((j + 20) % 100) * 0.1;
        x2_ve[j].im = (double)((j + 30) % 100) * 0.1;
        out_ve[j].re = 0.0;
        out_ve[j].im = 0.0;
    }

    x1_data.dim = num_elements;
    x1_data.max_dim = num_elements;
    x1_data.ve = x1_ve;

    x2_data.dim = num_elements;
    x2_data.max_dim = num_elements;
    x2_data.ve = x2_ve;

    out_data.dim = num_elements;
    out_data.max_dim = num_elements;
    out_data.ve = out_ve;

    i = 0;
    t_re = 0.0;
    t_im = 0.0;
}