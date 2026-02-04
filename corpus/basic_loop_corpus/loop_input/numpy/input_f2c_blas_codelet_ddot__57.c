#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef double doublereal;
typedef int integer;

doublereal *dx;
doublereal *dy;
integer i__1;
integer i__;
integer mp1;
doublereal dtemp;

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024; // ~64MB of data per array to ensure sufficient runtime
    const size_t num_elements = total_size / sizeof(doublereal);

    dx = (doublereal*)aligned_alloc(32, num_elements * sizeof(doublereal));
    dy = (doublereal*)aligned_alloc(32, num_elements * sizeof(doublereal));

    for (size_t i = 0; i < num_elements; ++i) {
        dx[i] = (doublereal)(rand() % 100) / 10.0;
        dy[i] = (doublereal)(rand() % 100) / 10.0;
    }

    mp1 = 1;
    i__1 = (integer)(num_elements - 5); 
    i__ = mp1;
    dtemp = 0.0;
}