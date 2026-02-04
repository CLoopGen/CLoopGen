#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
doublereal *z__ = NULL;
doublereal *dlamda = NULL;
doublereal *w = NULL;
integer *indx = NULL;
integer i__1 = 0;
integer i__ = 0;

void init_vars() {
    const size_t data_size = (1 << 24) / sizeof(doublereal); // ~16M elements for ~128MB total working set
    i__1 = (integer)data_size;

    d__ = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));
    z__ = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));
    dlamda = (doublereal*)malloc((i__1 + 1) * sizeof(doublereal));
    w = (doublereal*)malloc((i__1 + 1) * sizeof(doublereal));
    indx = (integer*)malloc((i__1 + 1) * sizeof(integer));

    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand((unsigned int)tv.tv_usec);

    for (integer i = 1; i <= i__1; ++i) {
        dlamda[i] = (doublereal)(rand() % 1000) / 3.14;
        w[i] = (doublereal)(rand() % 1000) / 2.71;
        indx[i] = rand() % i__1 + 1;
    }
}