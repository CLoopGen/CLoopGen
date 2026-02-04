#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *z__ = NULL;
integer i__1;
integer k;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of data (64M doubles)
    
    z__ = (doublereal*)calloc(data_size, sizeof(doublereal));
    if (!z__) exit(1);

    for (size_t i = 0; i < data_size; ++i) {
        z__[i] = (doublereal)(i + 1);
    }

    i__1 = (data_size - 1) / 4 + 1; // ensures (k<<2)-3 <= data_size-1 when k <= i__1
}