#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *k;
real *c__;
real *work;
integer c_dim1;
integer work_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer lastc;
integer lastv;

#define WORK_ROWS 512
#define WORK_COLS 512
#define C_ROWS 1024
#define C_COLS 1024

static integer k_storage;
static real *c_storage;
static real *work_storage;

void init_vars() {
    k = &k_storage;
    c_storage = (real*)calloc(C_ROWS * C_COLS, sizeof(real));
    work_storage = (real*)calloc(WORK_ROWS * WORK_COLS, sizeof(real));
    
    if (!c_storage || !work_storage) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    c__ = c_storage;
    work = work_storage;
    
    c_dim1 = C_ROWS;
    work_dim1 = WORK_ROWS;
    
    i__1 = WORK_COLS;
    lastc = WORK_ROWS;
    lastv = C_COLS;
    k_storage = 1;
    
    for (integer idx = 0; idx < WORK_ROWS * WORK_COLS; ++idx) {
        work_storage[idx] = (real)(idx % 100) / 10.0f;
    }
    
    for (integer idx = 0; idx < C_ROWS * C_COLS; ++idx) {
        c_storage[idx] = (real)(idx % 200) / 20.0f;
    }
}