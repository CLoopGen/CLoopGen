#include <stdint.h>
#include <stdlib.h>

int sulinesize = 1920;
int svlinesize = 1920;
int ulinesize = 1920;
int vlinesize = 1920;
int cbh = 960;
int cbv = 540;
int crh = 960;
int crv = 540;
int h = 1080;
int w = 1920;
int slice_start = 0;
int slice_end = 1080;

uint8_t *su;
uint8_t *sv;
uint8_t *du;
uint8_t *dv;

void init_vars() {
    su = aligned_alloc(32, (size_t)h * sulinesize);
    sv = aligned_alloc(32, (size_t)h * svlinesize);
    du = aligned_alloc(32, (size_t)h * ulinesize);
    dv = aligned_alloc(32, (size_t)h * vlinesize);

    if (!su || !sv || !du || !dv) {
        exit(1);
    }

    for (int i = 0; i < h * sulinesize; i++) {
        su[i] = rand() & 0xFF;
    }
    for (int i = 0; i < h * svlinesize; i++) {
        sv[i] = rand() & 0xFF;
    }
    for (int i = 0; i < h * ulinesize; i++) {
        du[i] = 0;
    }
    for (int i = 0; i < h * vlinesize; i++) {
        dv[i] = 0;
    }

    slice_start = 0;
    slice_end = 1080;
}