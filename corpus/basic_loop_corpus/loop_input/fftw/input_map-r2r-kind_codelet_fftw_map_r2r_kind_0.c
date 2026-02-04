#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

enum fftw_r2r_kind_do_not_use_me {
    FFTW_R2HC = 0,
    FFTW_HC2R = 1,
    FFTW_DHT = 2,
    FFTW_REDFT00 = 3,
    FFTW_REDFT01 = 4,
    FFTW_REDFT10 = 5,
    FFTW_REDFT11 = 6,
    FFTW_RODFT00 = 7,
    FFTW_RODFT01 = 8,
    FFTW_RODFT10 = 9,
    FFTW_RODFT11 = 10
};

typedef enum fftw_r2r_kind_do_not_use_me fftw_r2r_kind;

typedef enum {
    R2HC00,
    R2HC01,
    R2HC10,
    R2HC11,
    HC2R00,
    HC2R01,
    HC2R10,
    HC2R11,
    DHT,
    REDFT00,
    REDFT01,
    REDFT10,
    REDFT11,
    RODFT00,
    RODFT01,
    RODFT10,
    RODFT11
} rdft_kind;

int rank;
fftw_r2r_kind *kind;
int i;
rdft_kind *k;

void init_vars() {
    rank = 64 * 1024 * 1024 / sizeof(fftw_r2r_kind);
    kind = (fftw_r2r_kind*)aligned_alloc(32, rank * sizeof(fftw_r2r_kind));
    k = (rdft_kind*)aligned_alloc(32, rank * sizeof(rdft_kind));

    for (int idx = 0; idx < rank; ++idx) {
        kind[idx] = idx % 11;
    }
}