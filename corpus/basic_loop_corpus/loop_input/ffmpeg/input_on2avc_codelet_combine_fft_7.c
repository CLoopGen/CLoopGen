#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *s0;
float *s1;
float *s2;
float *s3;
float *t0;
float *t1;
float *t2;
float *t3;
int step;
float *h0;
float *h1;
float *h2;
float *h3;
float *d1;
float *d2;
int len4;
int i;
int j;
int k;

static float *alloc_aligned_float_array(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 32, n * sizeof(float)) != 0) {
        exit(1);
    }
    return (float *)ptr;
}

void init_vars() {
    const int total_data_size = 1 << 24; // ~16.7M floats, ~67MB total
    const int vec_len = total_data_size / 8; // Ensure large enough vectors

    s0 = alloc_aligned_float_array(vec_len);
    s1 = alloc_aligned_float_array(vec_len);
    s2 = alloc_aligned_float_array(vec_len);
    s3 = alloc_aligned_float_array(vec_len);
    t0 = alloc_aligned_float_array(vec_len);
    t1 = alloc_aligned_float_array(vec_len);
    t2 = alloc_aligned_float_array(vec_len);
    t3 = alloc_aligned_float_array(vec_len);
    h0 = alloc_aligned_float_array(vec_len);
    h1 = alloc_aligned_float_array(vec_len);
    h2 = alloc_aligned_float_array(vec_len);
    h3 = alloc_aligned_float_array(vec_len);
    d1 = alloc_aligned_float_array(vec_len);
    d2 = alloc_aligned_float_array(vec_len);

    step = 1;
    len4 = vec_len;
    j = len4 - 4; // ensures j+1 is valid when accessing sX[j+1]
    k = 0;

    for (int idx = 0; idx < vec_len; idx++) {
        s0[idx] = 1.0f + idx * 0.0001f;
        s1[idx] = 1.0f - idx * 0.0001f;
        s2[idx] = 0.5f + idx * 0.00005f;
        s3[idx] = 0.5f - idx * 0.00005f;
        t0[idx] = 0.1f;
        t1[idx] = 0.2f;
        t2[idx] = 0.3f;
        t3[idx] = 0.4f;
        h0[idx] = 0.9f;
        h1[idx] = 0.8f;
        h2[idx] = 0.7f;
        h3[idx] = 0.6f;
        d1[idx] = 0.0f;
        d2[idx] = 0.0f;
    }
}