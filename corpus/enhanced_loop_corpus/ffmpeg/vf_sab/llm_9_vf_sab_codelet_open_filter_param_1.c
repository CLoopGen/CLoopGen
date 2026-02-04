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
    // Variant 2: Reduced arithmetic complexity with unrolled inner loop and fixed small trip count
    int len = vec->length;
    for (y = 0; y < len; y++) {
        double cy = vec->coeff[y];
        x = 0;
        // Unroll inner loop by a factor of 4 for reduced branching and fewer arithmetic operations per update
        for (; x <= len - 4; x += 4) {
            double dx0 = vec->coeff[x + 0] * cy;
            double dx1 = vec->coeff[x + 1] * cy;
            double dx2 = vec->coeff[x + 2] * cy;
            double dx3 = vec->coeff[x + 3] * cy;

            f->dist_coeff[x + 0 + y * f->dist_linesize] = (int)(dx0 * (1 << 10) + 0.5);
            f->dist_coeff[x + 1 + y * f->dist_linesize] = (int)(dx1 * (1 << 10) + 0.5);
            f->dist_coeff[x + 2 + y * f->dist_linesize] = (int)(dx2 * (1 << 10) + 0.5);
            f->dist_coeff[x + 3 + y * f->dist_linesize] = (int)(dx3 * (1 << 10) + 0.5);
        }
        // Handle remaining elements
        for (; x < len; x++) {
            double d = vec->coeff[x] * cy;
            f->dist_coeff[x + y * f->dist_linesize] = (int)(d * (1 << 10) + 0.5);
        }
    }
}
