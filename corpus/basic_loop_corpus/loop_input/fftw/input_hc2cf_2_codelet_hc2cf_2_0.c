#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

R *Rp;
R *Ip;
R *Rm;
R *Im;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
INT m;

static size_t data_size;
static R *alloc_buffer;

void init_vars() {
    data_size = 64 * 1024 * 1024; // ~64MB of data to target ~0.01s runtime

    alloc_buffer = (R*)aligned_alloc(64, data_size);
    if (!alloc_buffer) {
        exit(1);
    }

    Rp = alloc_buffer;
    Ip = Rp + (data_size / (sizeof(R) * 8));
    Rm = Ip + (data_size / (sizeof(R) * 8));
    Im = Rm + (data_size / (sizeof(R) * 8));
    W = Im + (data_size / (sizeof(R) * 8));

    size_t w_size = 2 * (data_size / (sizeof(R) * 8)) + 100;
    size_t total_needed = (data_size / sizeof(R) * 8) * 5 + w_size;
    if (total_needed * sizeof(R) > data_size) {
        total_needed = data_size / sizeof(R);
    }

    for (size_t i = 0; i < total_needed; ++i) {
        alloc_buffer[i] = (R)(i % 1000) / 100.0;
    }

    ms = 1;
    mb = 1;
    me = (data_size / (sizeof(R) * 8)) - 10;
    rs = &ms;
}