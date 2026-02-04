#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer *n;
doublereal *z__;
doublereal *delta;
doublereal *work;
integer i__1;
integer j;
doublereal phi;

static doublereal *z_buffer;
static doublereal *delta_buffer;
static doublereal *work_buffer;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~192 MB of total data (3 arrays)
    const size_t num_elements = data_size / sizeof(doublereal);

    z_buffer = (doublereal*)aligned_alloc(64, (num_elements + 1) * sizeof(doublereal));
    delta_buffer = (doublereal*)aligned_alloc(64, (num_elements + 1) * sizeof(doublereal));
    work_buffer = (doublereal*)aligned_alloc(64, (num_elements + 1) * sizeof(doublereal));

    for (size_t i = 1; i <= num_elements; ++i) {
        z_buffer[i] = sin(i * 0.001);
        delta_buffer[i] = fabs(cos(i * 0.001)) + 1.0;
        work_buffer[i] = fabs(sin(i * 0.001)) + 1.0;
    }

    n = (integer*)aligned_alloc(64, sizeof(integer));
    *n = (integer)num_elements;

    i__1 = 1;

    z__ = z_buffer;
    delta = delta_buffer;
    work = work_buffer;

    phi = 0.0;
}