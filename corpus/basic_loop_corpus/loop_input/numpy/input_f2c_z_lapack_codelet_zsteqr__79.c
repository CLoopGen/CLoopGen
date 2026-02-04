#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *e;
integer *info;
integer i__1;
integer i__;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data: 2^20 doubles ≈ 8MB
    e = (doublereal *)calloc(data_size, sizeof(doublereal));
    if (!e) {
        exit(1);
    }

    for (size_t i = 1; i < data_size; ++i) {
        if ((rand() % 4) == 0) {
            e[i] = 1.0;
        }
    }

    i__1 = (integer)(data_size - 1);
    info = (integer *)malloc(sizeof(integer));
    if (!info) {
        exit(1);
    }
    *info = 0;
}