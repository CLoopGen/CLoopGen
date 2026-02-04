#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer *i0;
doublereal *z__;
doublereal *tau;
doublereal *dmin__;
integer i__1;
doublereal d__1;
doublereal d__;
integer j4;
doublereal emin;
doublereal temp;

#define DATA_SIZE_MB 64
#define ARRAY_SIZE ((DATA_SIZE_MB * 1024 * 1024) / sizeof(doublereal))

static doublereal z_array[ARRAY_SIZE];
static integer local_i0;
static doublereal local_tau;
static doublereal local_dmin;
static integer local_i__1;

void init_vars() {
    const double target_time_seconds = 0.01;
    const double est_operations_per_sec = 2e9;
    const double operations_per_iteration = 10;
    
    i0 = &local_i0;
    tau = &local_tau;
    dmin__ = &local_dmin;
    
    z__ = z_array;
    
    local_i0 = 10;
    local_tau = 0.5;
    local_dmin = 1.0;
    d__ = 1.0;
    emin = 1e10;
    temp = 0.0;
    d__1 = 0.0;
    
    size_t safe_size = ARRAY_SIZE;
    if (safe_size < 100) {
        safe_size = 100;
    }
    
    for (size_t i = 0; i < safe_size; ++i) {
        z__[i] = 1.0 + 0.01 * (i % 100);
    }
    
    local_i__1 = (safe_size - 4) & ~3;
    if (local_i__1 < (*i0 << 2)) {
        local_i__1 = (*i0 << 2) + 4;
        while (local_i__1 + 4 >= (int)safe_size) {
            local_i__1 -= 4;
        }
    }
    i__1 = local_i__1;
}