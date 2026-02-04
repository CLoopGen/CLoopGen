#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *i__;
real *d__;
real *delta;
real *work;
integer i__1;
integer j;
real temp;

static integer local_i_val = 1048576;  // 1MB of data: 1M integers ~ 4MB total for arrays
static real *local_d_array = NULL;
static real *local_delta_array = NULL;
static real *local_work_array = NULL;

void init_vars() {
    i__1 = local_i_val;
    temp = 1.0f;
    j = 0;  // Will be incremented in loop

    // Allocate arrays with size i__1 + 1 to allow 1-based indexing up to i__1
    local_d_array = (real*)calloc(local_i_val + 1, sizeof(real));
    local_delta_array = (real*)calloc(local_i_val + 1, sizeof(real));
    local_work_array = (real*)calloc(local_i_val + 1, sizeof(real));

    if (!local_d_array || !local_delta_array || !local_work_array) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize d__ array with sample values
    for (integer idx = 1; idx <= i__1; ++idx) {
        local_d_array[idx] = (real)(idx * 0.5f);
    }

    // Set pointer variables to point to allocated storage
    i__ = &local_i_val;
    d__ = local_d_array;
    delta = local_delta_array;
    work = local_work_array;
}