#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *z__;
integer i__1;
integer k;

void init_vars() {
    i__1 = 67108864;  // Approximately 256 MB of float data (67M elements * 4 bytes)
    z__ = (real*)calloc(i__1 + 1, sizeof(real));
    if (!z__) {
        exit(1);
    }
}