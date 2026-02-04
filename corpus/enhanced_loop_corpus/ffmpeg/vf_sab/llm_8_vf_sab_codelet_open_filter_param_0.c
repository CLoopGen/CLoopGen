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
    for (i = 0; i < 256; i++) {
        double d;
        int index1 = i - 256 + vec->length / 2;
        int index2 = i + 256 - vec->length / 2;
        if (index1 >= 0 && index1 < vec->length)
            d = vec->coeff[index1];
        else if (index2 >= 0 && index2 < vec->length)
            d = vec->coeff[index2] * 0.5;
        else
            d = 0.;
        f->color_diff_coeff[i] = (int)(d / vec->coeff[vec->length / 2] * (1 << 12) + 0.5);
        f->color_diff_coeff[i + 256] = (int)(d / vec->coeff[vec->length / 2] * (1 << 11) + 0.5);
    }
}
