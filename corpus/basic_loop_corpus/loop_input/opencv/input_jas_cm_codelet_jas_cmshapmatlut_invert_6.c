#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double jas_cmreal_t;

typedef struct {
    jas_cmreal_t *data;
    int size;
} jas_cmshapmatlut_t;

jas_cmreal_t *data1;
jas_cmreal_t *data2;
jas_cmshapmatlut_t inlut_inst;
jas_cmshapmatlut_t outlut_inst;

jas_cmshapmatlut_t *invlut = &inlut_inst;
jas_cmshapmatlut_t *lut = &outlut_inst;

int i;
int j;
int k;
jas_cmreal_t ax;
jas_cmreal_t ay;
jas_cmreal_t bx;
jas_cmreal_t by;
jas_cmreal_t sx;
jas_cmreal_t sy;

void init_vars() {
    const int size = 16384; // Approximate data size for ~0.01s runtime

    data1 = (jas_cmreal_t*)calloc(size, sizeof(jas_cmreal_t));
    data2 = (jas_cmreal_t*)calloc(size, sizeof(jas_cmreal_t));

    inlut_inst.data = data1;
    inlut_inst.size = size;

    outlut_inst.data = data2;
    outlut_inst.size = size;

    for (int idx = 0; idx < size; ++idx) {
        data2[idx] = ((jas_cmreal_t)idx / (size - 1)) * 0.95 + ((jas_cmreal_t)rand() / RAND_MAX) * 0.05;
    }

    for (int idx = 0; idx < size; ++idx) {
        data1[idx] = 0.0;
    }

    i = 0;
    j = 0;
    k = 0;
    ax = 0.0;
    ay = 0.0;
    bx = 0.0;
    by = 0.0;
    sx = 0.0;
    sy = 0.0;
}