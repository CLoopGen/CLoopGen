#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

doublecomplex *v;
integer *incv;
integer i__1;
integer i__;
integer lastv;

static doublecomplex *v_data;
static integer incv_data;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 MB of complex doubles
    v_data = aligned_alloc(32, data_size * sizeof(doublecomplex));
    if (!v_data) abort();

    for (size_t idx = 0; idx < data_size; ++idx) {
        v_data[idx].r = 0.0;
        v_data[idx].i = 0.0;
    }

    const size_t nonzero_count = 1000;
    for (size_t idx = 0; idx < nonzero_count; ++idx) {
        size_t pos = rand() % data_size;
        v_data[pos].r = sin(pos);
        v_data[pos].i = cos(pos);
    }

    v = v_data;
    incv = &incv_data;
    *incv = 1;
    i__ = data_size - 1;
    lastv = data_size;
}