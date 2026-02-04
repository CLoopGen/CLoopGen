#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *t;
integer t_dim1;
integer i__1;
integer j;

void init_vars() {
    const size_t target_size = 64 * 1024 * 1024; // Aim for ~64 MB of data
    const size_t element_size = sizeof(doublereal);
    const size_t num_elements = target_size / element_size;

    t_dim1 = (integer)sqrt((double)num_elements);
    if (t_dim1 < 2) t_dim1 = 2;

    i__1 = t_dim1 - 3; 
    if (i__1 < 1) i__1 = 1;

    t = (doublereal*)calloc(num_elements, element_size);
    if (!t) {
        exit(1);
    }
}