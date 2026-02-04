#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef double doublereal;
typedef int integer;

doublereal *da;
doublereal *dx;
doublereal *dy;
integer i__1;
integer i__;
integer mp1;

static doublereal da_data;
static doublereal *dx_data;
static doublereal *dy_data;
static size_t data_size;

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    data_size = 64 * 1024 * 1024 / sizeof(doublereal); // ~64 MB of data

    dx_data = (doublereal*)aligned_alloc(32, data_size * sizeof(doublereal));
    dy_data = (doublereal*)aligned_alloc(32, data_size * sizeof(doublereal));

    if (!dx_data || !dy_data) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        dx_data[i] = 1.0 + (i % 7);
        dy_data[i] = 2.0 + (i % 5);
    }

    da_data = 0.5;

    da = &da_data;
    dx = dx_data;
    dy = dy_data;

    mp1 = 0;
    i__1 = (integer)(data_size - 4);

    do {
        i__ = mp1;
        while (i__ <= i__1) {
            dy[i__] += *da * dx[i__];
            dy[i__ + 1] += *da * dx[i__ + 1];
            dy[i__ + 2] += *da * dx[i__ + 2];
            dy[i__ + 3] += *da * dx[i__ + 3];
            i__ += 4;
        }
        gettimeofday(&end, NULL);
    } while (((end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec)) < 10000);

    for (size_t i = 0; i < data_size; ++i) {
        dy_data[i] = 2.0 + (i % 5);
    }
}