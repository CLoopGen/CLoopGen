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
    int y, x1, x2, x3, x4;
    int len = vec->length;
    for (y = 0; y < len; y += 4) {
        for (x1 = 0; x1 < len; x1++) {
            int y1 = y;
            if (y1 < len) {
                double d1 = vec->coeff[x1] * vec->coeff[y1];
                f->dist_coeff[x1 + y1 * f->dist_linesize] = (int)(d1 * (1 << 10) + 0.5);
            }
            int y2 = y + 1;
            if (y2 < len) {
                double d2 = vec->coeff[x1] * vec->coeff[y2];
                f->dist_coeff[x1 + y2 * f->dist_linesize] = (int)(d2 * (1 << 10) + 0.5);
            }
            int y3 = y + 2;
            if (y3 < len) {
                double d3 = vec->coeff[x1] * vec->coeff[y3];
                f->dist_coeff[x1 + y3 * f->dist_linesize] = (int)(d3 * (1 << 10) + 0.5);
            }
            int y4 = y + 3;
            if (y4 < len) {
                double d4 = vec->coeff[x1] * vec->coeff[y4];
                f->dist_coeff[x1 + y4 * f->dist_linesize] = (int)(d4 * (1 << 10) + 0.5);
            }
        }
    }
}
