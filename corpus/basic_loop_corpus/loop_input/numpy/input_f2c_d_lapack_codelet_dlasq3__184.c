#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;
typedef double doublereal;

integer *i0;
doublereal *z__;
integer i__1;
integer j4;
integer ipn4;
doublereal temp;

static doublereal z_array[65536];
static integer i0_value;

void init_vars() {
    i0_value = 1;
    i0 = &i0_value;
    
    const size_t array_size = 65536;
    z__ = z_array;
    i__1 = (integer)(array_size - 4);
    ipn4 = (integer)array_size + 4;
    temp = 0.0;
    
    for (size_t i = 0; i < array_size; ++i) {
        z__[i] = (doublereal)(i + 1);
    }
}