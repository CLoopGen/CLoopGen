#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int sulinesize = 1920;
int svlinesize = 1920;
int ulinesize = 1920;
int vlinesize = 1920;
int cbh = 8;
int cbv = 4;
int crh = 16;
int crv = 8;
int h = 1080;
int w = 1920;
int slice_start = 0;
int slice_end = 1080;

uint16_t *su;
uint16_t *sv;
uint16_t *du;
uint16_t *dv;

void init_vars() {
    size_t su_size = (size_t)sulinesize * h * sizeof(uint16_t);
    size_t sv_size = (size_t)svlinesize * h * sizeof(uint16_t);
    size_t du_size = (size_t)ulinesize * h * sizeof(uint16_t);
    size_t dv_size = (size_t)vlinesize * h * sizeof(uint16_t);

    su = (uint16_t*)aligned_alloc(32, su_size);
    sv = (uint16_t*)aligned_alloc(32, sv_size);
    du = (uint16_t*)aligned_alloc(32, du_size);
    dv = (uint16_t*)aligned_alloc(32, dv_size);

    if (!su || !sv || !du || !dv) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < su_size / sizeof(uint16_t); i++) {
        su[i] = (uint16_t)(i % 32768);
    }
    for (size_t i = 0; i < sv_size / sizeof(uint16_t); i++) {
        sv[i] = (uint16_t)((i * 3) % 32768);
    }
    for (size_t i = 0; i < du_size / sizeof(uint16_t); i++) {
        du[i] = 0;
    }
    for (size_t i = 0; i < dv_size / sizeof(uint16_t); i++) {
        dv[i] = 0;
    }

    slice_start = 0;
    slice_end = h;
}