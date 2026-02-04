#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <sys/time.h>

typedef int integer;
typedef double doublereal;

integer i__1 = 1048576; // Size of arrays, ~8MB for d__ and delta each (total ~24MB)
integer *i__ = NULL;
doublereal *d__ = NULL;
doublereal *delta = NULL;
doublereal midpt = 123.456;
integer j;

void init_vars() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand((unsigned int)(tv.tv_sec * 1000 + tv.tv_usec / 1000));

    i__ = (integer*)malloc(sizeof(integer));
    *i__ = 1 + (rand() % i__1); // Ensure *i__ is within [1, i__1]

    d__ = (doublereal*)malloc((i__1 + 1) * sizeof(doublereal));
    delta = (doublereal*)malloc((i__1 + 1) * sizeof(doublereal));

    for (integer idx = 1; idx <= i__1; ++idx) {
        d__[idx] = (doublereal)(rand() % 1000) / 10.0;
        delta[idx] = 0.0;
    }

    midpt = 123.456;
}