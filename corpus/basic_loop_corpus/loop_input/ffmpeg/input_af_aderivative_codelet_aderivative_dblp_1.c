#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

void **d;
void **p;
void **s;
int nb_samples;
int channels;
int n;
int c;

#define DATA_SIZE_MB 64

static double *alloc_aligned_double_array(size_t count) {
    void *ptr;
    if (posix_memalign(&ptr, 32, count * sizeof(double)) != 0) {
        exit(1);
    }
    return (double *)ptr;
}

void init_vars() {
    channels = 8;
    nb_samples = (DATA_SIZE_MB * 1024 * 1024) / (channels * sizeof(double));
    
    s = malloc(channels * sizeof(void*));
    d = malloc(channels * sizeof(void*));
    p = malloc(channels * sizeof(void*));
    
    if (!s || !d || !p) {
        exit(1);
    }
    
    for (int c = 0; c < channels; c++) {
        double *src_data = alloc_aligned_double_array(nb_samples);
        double *dst_data = alloc_aligned_double_array(nb_samples);
        double *prv_data = alloc_aligned_double_array(1);
        
        if (!src_data || !dst_data || !prv_data) {
            exit(1);
        }
        
        for (int n = 0; n < nb_samples; n++) {
            src_data[n] = (double)(n + c);
        }
        prv_data[0] = 0.0;
        
        s[c] = src_data;
        d[c] = dst_data;
        p[c] = prv_data;
    }
}