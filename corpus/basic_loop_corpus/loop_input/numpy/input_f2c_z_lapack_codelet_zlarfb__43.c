#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *k;
doublecomplex *c__;
doublecomplex *work;
integer c_dim1;
integer work_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
doublecomplex z__1;
integer i__;
integer j;
integer lastc;
integer lastv;

static doublecomplex *c_storage;
static doublecomplex *work_storage;
static integer k_storage;

void init_vars() {
    const integer target_mb = 64;
    const size_t target_bytes = (size_t)target_mb * (1 << 20);
    
    lastv = (integer)sqrt(target_bytes / (sizeof(doublecomplex) * 2));
    lastc = (integer)sqrt(target_bytes / (sizeof(doublecomplex) * 2));
    if (lastv < 1) lastv = 1;
    if (lastc < 1) lastc = 1;
    
    k_storage = 1;
    k = &k_storage;
    
    i__1 = 100;
    *k = 1;
    
    c_dim1 = lastc;
    work_dim1 = lastc;
    
    size_t c_size = (size_t)lastc * (lastv - *k + i__1) + lastc;
    size_t work_size = (size_t)lastc * i__1 + lastc;
    
    c_storage = (doublecomplex*)calloc(c_size, sizeof(doublecomplex));
    work_storage = (doublecomplex*)calloc(work_size, sizeof(doublecomplex));
    
    if (!c_storage || !work_storage) {
        exit(1);
    }
    
    c__ = c_storage;
    work = work_storage;
    
    for (size_t idx = 0; idx < c_size; ++idx) {
        c_storage[idx].r = sin(idx);
        c_storage[idx].i = cos(idx);
    }
    for (size_t idx = 0; idx < work_size; ++idx) {
        work_storage[idx].r = 0.5 * sin(idx + 1.0);
        work_storage[idx].i = 0.5 * cos(idx + 1.0);
    }
}