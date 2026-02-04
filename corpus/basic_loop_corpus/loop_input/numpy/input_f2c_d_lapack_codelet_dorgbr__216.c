#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *a;
integer a_dim1;
integer i__1;
integer i__;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // ~128MB of data
    const size_t num_elements = data_size / sizeof(doublereal);

    a_dim1 = (integer)num_elements > 10000 ? 10000 : (integer)num_elements - 1;
    i__1 = (integer)num_elements > 20000 ? 20000 : (integer)num_elements - 1;

    if (i__1 <= 1) {
        i__1 = 1;
    }

    a = (doublereal*)calloc(num_elements, sizeof(doublereal));
    if (!a) {
        exit(1);
    }
}