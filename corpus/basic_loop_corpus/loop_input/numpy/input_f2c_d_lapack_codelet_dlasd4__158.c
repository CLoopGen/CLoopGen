#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer *n;
doublereal *z__;
doublereal *delta;
doublereal *work;
integer i__1;
integer j;
doublereal phi;
doublereal dphi;
doublereal temp;
doublereal erretm;

#define DATA_SIZE (1 << 20) // Approximately 1MB of data per array (each double is 8 bytes)

static doublereal z_array[DATA_SIZE];
static doublereal delta_array[DATA_SIZE];
static doublereal work_array[DATA_SIZE];

void init_vars() {
    // Initialize scalar variables
    n = (integer*)malloc(sizeof(integer));
    *n = DATA_SIZE - 1;  // Set n to last valid index
    i__1 = 0;              // Loop down to 0
    phi = 0.0;
    dphi = 0.0;
    temp = 0.0;
    erretm = 0.0;

    // Initialize array pointers
    z__ = z_array;
    delta = delta_array;
    work = work_array;

    // Initialize array data to avoid division by zero and ensure predictable behavior
    for (integer i = 0; i < DATA_SIZE; ++i) {
        z__[i] = (doublereal)(i + 1);
        work[i] = (doublereal)(i + 1) * 0.5;
        delta[i] = (doublereal)(i + 1) * 2.0;
    }
}