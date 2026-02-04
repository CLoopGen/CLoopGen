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

static double **d_data;
static double **p_data;
static double **s_data;
static double *prv_pool;
static double *dst_pool;
static double *src_pool;

void init_vars() {
    channels = 8;
    nb_samples = 4000000; // ~256MB of data (8 ch * 4M samples * 8 bytes * 3 arrays)

    d_data = malloc(channels * sizeof(double*));
    p_data = malloc(channels * sizeof(double*));
    s_data = malloc(channels * sizeof(double*));

    prv_pool = malloc(channels * sizeof(double));
    dst_pool = malloc(channels * nb_samples * sizeof(double));
    src_pool = malloc(channels * nb_samples * sizeof(double));

    d = (void**)d_data;
    p = (void**)p_data;
    s = (void**)s_data;

    for (int c = 0; c < channels; c++) {
        s_data[c] = &src_pool[c * nb_samples];
        d_data[c] = &dst_pool[c * nb_samples];
        p_data[c] = &prv_pool[c];
        prv_pool[c] = 0.0;
        for (int n = 0; n < nb_samples; n++) {
            src_pool[c * nb_samples + n] = (double)(n + 1) * 0.001;
        }
    }
}