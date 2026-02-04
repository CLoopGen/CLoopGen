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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse traversal
    for (i = 511; i >= 0; i--) {
        double d;
        int index = i - 512 / 2 + vec->length / 2;
        if (index < 0 || index >= vec->length)
            d = 0.;
        else
            d = vec->coeff[index];
        f->color_diff_coeff[i] = (int)(d / vec->coeff[vec->length / 2] * (1 << 12) + 0.5);
    }
}
