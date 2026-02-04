#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;
typedef double doublereal;

integer i__1 = 0;
integer j = 0;
doublereal temp = 0.0;

static integer static_i = 0;
integer *i__ = &static_i;

static doublereal *d_static = NULL;
doublereal *d__ = NULL;

static doublereal *work_static = NULL;
doublereal *work = NULL;

static doublereal *delta_static = NULL;
doublereal *delta = NULL;

void init_vars() {
    const size_t data_size_bytes = 64 * 1024 * 1024; 
    const size_t element_size = sizeof(doublereal);
    const integer array_len = data_size_bytes / element_size;

    d_static = (doublereal*)calloc(array_len + 2, sizeof(doublereal));
    work_static = (doublereal*)calloc(array_len + 2, sizeof(doublereal));
    delta_static = (doublereal*)calloc(array_len + 2, sizeof(doublereal));

    if (!d_static || !work_static || !delta_static) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    d__ = d_static;
    work = work_static;
    delta = delta_static;

    for (integer idx = 1; idx <= array_len; ++idx) {
        d__[idx] = (doublereal)(idx * 0.5);
    }

    i__1 = array_len;
    static_i = array_len; 
    temp = 1.5;
}