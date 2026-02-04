#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef float real;
typedef int integer;

real *d__ = NULL;
integer *indxq = NULL;
real *dlamda = NULL;
integer i__1;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of total data (adjustable)
    
    i__1 = data_size;

    d__ = (real *)aligned_alloc(32, sizeof(real) * data_size);
    indxq = (integer *)aligned_alloc(32, sizeof(integer) * (data_size + 1));
    dlamda = (real *)aligned_alloc(32, sizeof(real) * (data_size + 1));

    for (size_t i = 0; i < data_size; ++i) {
        d__[i] = (real)(rand() % 1000) / 10.0f;
    }

    for (integer i = 1; i <= i__1; ++i) {
        indxq[i] = rand() % data_size;
    }

    for (integer i = 1; i <= i__1; ++i) {
        dlamda[i] = 0.0f;
    }
}