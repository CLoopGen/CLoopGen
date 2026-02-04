#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
doublereal *work = NULL;
integer *iwork = NULL;
integer i__1 = 0;
integer i__ = 0;
integer j = 0;
integer indxq = 0;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of total data, adjust for ~0.01s runtime

    i__1 = data_size / sizeof(doublereal);
    if (i__1 > 10000000) i__1 = 10000000; // Cap to avoid excessive memory use

    free((void*)d__);
    free((void*)work);
    free((void*)iwork);

    d__ = (doublereal*)calloc(data_size, sizeof(doublereal));
    work = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));
    iwork = (integer*)calloc(i__1 + 1, sizeof(integer));

    if (!d__ || !work || !iwork) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (integer idx = 0; idx <= i__1; ++idx) {
        d__[idx] = (doublereal)(idx * 2);
        iwork[indxq + idx] = idx % i__1;
    }
}