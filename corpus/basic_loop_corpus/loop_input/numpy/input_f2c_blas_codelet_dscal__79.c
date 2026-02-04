#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *da;
doublereal *dx;
integer i__2;
integer i__;
integer mp1;

static doublereal da_data;
static doublereal *dx_data;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~512 MB of dx data (64M doubles)

    da = &da_data;
    dx_data = (doublereal*)aligned_alloc(32, data_size);
    if (!dx_data) exit(1);

    dx = dx_data;

    *da = 2.5;
    for (size_t i = 0; i < data_size / sizeof(doublereal); ++i) {
        dx[i] = (doublereal)(i + 1);
    }

    mp1 = 0;
    i__2 = (data_size / sizeof(doublereal)) - 5;
}