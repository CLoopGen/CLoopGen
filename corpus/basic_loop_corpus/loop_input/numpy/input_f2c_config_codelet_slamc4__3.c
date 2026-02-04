#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <sys/time.h>

typedef int integer;
typedef float real;

integer i__1;
integer i__;
real b1;
real d1;

void init_vars() {
    struct timeval tv_start, tv_end;
    double elapsed;
    long long count;
    real temp_d1;

    i__ = 0;
    b1 = 1.5f;
    d1 = 0.0f;

    for (count = 1; ; count *= 2) {
        i__1 = (integer)count;
        temp_d1 = 0.0f;
        gettimeofday(&tv_start, NULL);
        for (i__ = 1; i__ <= i__1; ++i__) {
            temp_d1 += b1;
        }
        gettimeofday(&tv_end, NULL);

        elapsed = (tv_end.tv_sec - tv_start.tv_sec) + (tv_end.tv_usec - tv_start.tv_usec) / 1e6;
        if (elapsed >= 0.01) break;
        if (count > 1L << 30) break;
    }

    i__1 = (integer)count;
    d1 = 0.0f;
}