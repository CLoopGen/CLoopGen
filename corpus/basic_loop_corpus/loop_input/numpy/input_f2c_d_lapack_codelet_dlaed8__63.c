#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
integer *indxq = NULL;
doublereal *dlamda = NULL;
integer *perm = NULL;
integer *indxp = NULL;
integer *indx = NULL;
integer i__1;
integer j;
integer jp;

static size_t data_size;

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    data_size = 1 << 20; // Start with ~8MB of data (assuming double and int arrays)

    d__ = (doublereal*)calloc(data_size, sizeof(doublereal));
    indxq = (integer*)calloc(data_size, sizeof(integer));
    dlamda = (doublereal*)calloc(data_size, sizeof(doublereal));
    perm = (integer*)calloc(data_size, sizeof(integer));
    indxp = (integer*)calloc(data_size, sizeof(integer));
    indx = (integer*)calloc(data_size, sizeof(integer));

    for (size_t i = 0; i < data_size; ++i) {
        d__[i] = (doublereal)(i + 1);
        indxq[i] = (integer)(i % 1000);
        indxp[i] = (integer)((data_size - i - 1) % data_size);
        indx[i] = (integer)((i * 7) % data_size);
    }

    i__1 = (integer)data_size;

    do {
        gettimeofday(&end, NULL);
        double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
        if (elapsed >= 0.01) break;

        free(d__); free(indxq); free(dlamda); free(perm); free(indxp); free(indx);

        data_size *= 1.5;
        if (data_size > (1 << 28)) data_size = (1 << 28); 

        d__ = (doublereal*)calloc(data_size, sizeof(doublereal));
        indxq = (integer*)calloc(data_size, sizeof(integer));
        dlamda = (doublereal*)calloc(data_size, sizeof(doublereal));
        perm = (integer*)calloc(data_size, sizeof(integer));
        indxp = (integer*)calloc(data_size, sizeof(integer));
        indx = (integer*)calloc(data_size, sizeof(integer));

        for (size_t i = 0; i < data_size; ++i) {
            d__[i] = (doublereal)(i + 1);
            indxq[i] = (integer)(i % 1000);
            indxp[i] = (integer)((data_size - i - 1) % data_size);
            indx[i] = (integer)((i * 7) % data_size);
        }

        i__1 = (integer)data_size;
    } while (1);
}