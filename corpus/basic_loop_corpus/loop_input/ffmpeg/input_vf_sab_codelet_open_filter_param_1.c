#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct SwsContext {
    int dummy;
} SwsContext;

typedef struct FilterParam {
    float radius;
    float pre_filter_radius;
    float strength;
    float quality;
    struct SwsContext *pre_filter_context;
    uint8_t *pre_filter_buf;
    int pre_filter_linesize;
    int dist_width;
    int dist_linesize;
    int *dist_coeff;
    int color_diff_coeff[512];
} FilterParam;

typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

FilterParam *f;
SwsVector *vec;
int x;
int y;

static int *g_dist_coeff = NULL;
static double *g_vec_coeff = NULL;

void init_vars() {
    const int size = 1024;  // Adjusted for ~0.01 sec runtime (approx 8MB data)
    
    g_vec_coeff = (double*)calloc(size, sizeof(double));
    if (!g_vec_coeff) exit(1);
    
    for (int i = 0; i < size; i++) {
        g_vec_coeff[i] = (double)(i % 128) / 64.0;
    }
    
    vec = (SwsVector*)malloc(sizeof(SwsVector));
    if (!vec) exit(1);
    vec->coeff = g_vec_coeff;
    vec->length = size;
    
    f = (FilterParam*)malloc(sizeof(FilterParam));
    if (!f) exit(1);
    
    f->dist_width = size;
    f->dist_linesize = size;
    
    g_dist_coeff = (int*)calloc(size * size, sizeof(int));
    if (!g_dist_coeff) exit(1);
    
    f->dist_coeff = g_dist_coeff;
    
    f->radius = 1.0f;
    f->pre_filter_radius = 0.5f;
    f->strength = 2.0f;
    f->quality = 3.0f;
    f->pre_filter_context = NULL;
    f->pre_filter_buf = NULL;
    f->pre_filter_linesize = 0;
    
    for (int i = 0; i < 512; i++) {
        f->color_diff_coeff[i] = i - 256;
    }
}