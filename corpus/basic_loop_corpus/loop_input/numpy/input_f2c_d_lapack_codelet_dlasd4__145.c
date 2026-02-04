#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer *n;
doublereal *d__;
doublereal *delta;
doublereal *work;
integer i__1;
integer j;
doublereal temp1;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(doublereal)) // ~512MB total for arrays

static doublereal d_array[DATA_SIZE];
static doublereal delta_array[DATA_SIZE];
static doublereal work_array[DATA_SIZE];

void init_vars() {
    const integer max_n = DATA_SIZE - 1;
    
    n = (integer*)malloc(sizeof(integer));
    *n = max_n;

    d__ = d_array;
    delta = delta_array;
    work = work_array;

    i__1 = max_n;

    temp1 = 3.14159;

    for (integer i = 1; i <= max_n; ++i) {
        d__[i] = sin(i);
    }
}