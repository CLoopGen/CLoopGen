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
    for (y = 0; y < vec->length; y++) {
        int skip = (y % 3 == 0);
        for (x = 0; x < vec->length; x++) {
            if (skip && x < vec->length / 2) {
                continue;
            }
            double d = vec->coeff[x] * vec->coeff[y];
            f->dist_coeff[x + y * f->dist_linesize] = (int)(d * (1 << 10) + 0.5);
        }
    }
}
