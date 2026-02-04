#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef int integer;
typedef double doublereal;

integer i__1;
integer i__;
doublereal b1;
doublereal d1;

void init_vars() {
    b1 = 1.5;
    d1 = 0.0;
    i__1 = 10000000; // Adjusted for ~0.01 sec runtime on modern CPU
}