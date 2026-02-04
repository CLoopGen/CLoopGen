#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *work;
integer i__1;
doublereal d__1;
doublereal d__2;
integer i__;
doublereal value;

static doublereal work_buffer[134217728 / sizeof(doublereal)]; // 134MB buffer to ensure ~0.01s runtime

void init_vars() {
    i__ = 0;
    i__1 = 134217728 / sizeof(doublereal) - 1; // Adjust so i__ goes from 1 to i__1 within bounds
    value = 0.0;
    d__1 = 0.0;
    d__2 = 0.0;
    work = work_buffer;

    for (int i = 0; i <= i__1; ++i) {
        work[i] = sin(i * 0.00001);
    }
}