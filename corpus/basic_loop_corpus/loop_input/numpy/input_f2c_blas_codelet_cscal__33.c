#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *ca;
singlecomplex *cx;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
singlecomplex q__1;
integer i__;

static singlecomplex ca_storage;
static singlecomplex *cx_storage;
static size_t cx_size;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 MB for target execution time
    cx_size = data_size / sizeof(singlecomplex);

    cx_storage = aligned_alloc(32, data_size);
    if (!cx_storage) {
        exit(1);
    }

    ca = &ca_storage;
    cx = cx_storage;

    ca->r = 1.5f;
    ca->i = 0.8f;

    for (size_t idx = 0; idx < cx_size; ++idx) {
        cx[idx].r = sinf(idx % 100);
        cx[idx].i = cosf(idx % 100);
    }

    i__1 = cx_size - 1;
    i__2 = 1;
    i__ = 0;
    i__3 = 0;
    i__4 = 0;
}