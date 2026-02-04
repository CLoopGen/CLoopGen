#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef double doublereal;
typedef int integer;

doublereal *e;
integer *info;
integer i__1;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of doubles
    e = (doublereal *)aligned_alloc(32, data_size * sizeof(doublereal));
    if (!e) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        e[i] = (i % 7 == 0) ? 0.0 : 1.5; // sparse zeros
    }

    info = (integer *)malloc(sizeof(integer));
    if (!info) {
        exit(1);
    }
    *info = 0;

    i__1 = (integer)(data_size - 1); // ensure e[i__] access is valid for i__ from 1 to i__1
    i__ = 0;
}