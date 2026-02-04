#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *d__;
doublereal *e;
integer *iwork;
integer i__1;
doublereal d__1;
integer i__;
integer smm1;
integer submat;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements, adjust for ~0.01 sec runtime
    const size_t num_elements = data_size / sizeof(doublereal);

    i__1 = (integer)(num_elements * 0.8); // ensure we stay within bounds

    d__ = (doublereal*)calloc(num_elements, sizeof(doublereal));
    e = (doublereal*)calloc(num_elements, sizeof(doublereal));
    iwork = (integer*)malloc(num_elements * sizeof(integer));

    if (!d__ || !e || !iwork) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < num_elements; ++i) {
        d__[i] = (doublereal)(rand() % 1000) / 10.0;
        e[i] = (doublereal)(rand() % 1000) / 10.0;
        iwork[i] = (integer)(i % (num_elements - 10)); // ensure submat+1 stays in range
    }
}