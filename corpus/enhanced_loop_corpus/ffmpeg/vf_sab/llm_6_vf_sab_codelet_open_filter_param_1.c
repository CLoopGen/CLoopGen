#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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

extern FilterParam *f;
extern SwsVector *vec;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int len = vec->length;
    int linesize = f->dist_linesize;
    int *dist_coeff = f->dist_coeff;
    double *coeff = vec->coeff;

    for (y = 0; y < len; y++) {
        double cy = coeff[y];
        for (x = 0; x < len; x++) {
            double d = coeff[x] * cy;
            dist_coeff[x + y * linesize] = (int)(d * (1 << 10) + 0.5);
        }
    }
}
