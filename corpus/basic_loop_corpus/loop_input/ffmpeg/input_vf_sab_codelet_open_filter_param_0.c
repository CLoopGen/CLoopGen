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
int i;

static double *g_vec_coeff;
static int *g_dist_coeff;

void init_vars() {
    g_vec_coeff = (double*)calloc(512, sizeof(double));
    g_dist_coeff = (int*)calloc(512, sizeof(int));
    
    vec = (SwsVector*)malloc(sizeof(SwsVector));
    f = (FilterParam*)malloc(sizeof(FilterParam));
    
    vec->length = 512;
    vec->coeff = g_vec_coeff;
    
    for (int j = 0; j < vec->length; j++) {
        vec->coeff[j] = (double)(j + 1);
    }
    
    f->pre_filter_context = (SwsContext*)malloc(sizeof(SwsContext));
    f->pre_filter_buf = (uint8_t*)malloc(1024 * 1024);
    f->pre_filter_linesize = 1024;
    f->dist_width = 512;
    f->dist_linesize = 512;
    f->dist_coeff = g_dist_coeff;
    
    for (int j = 0; j < 512; j++) {
        f->color_diff_coeff[j] = 0;
    }
}