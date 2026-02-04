#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *tau;
integer i__1;
integer i__2;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements, each 8 bytes -> ~512MB
    tau = (singlecomplex*)calloc(data_size, sizeof(singlecomplex));
    if (!tau) {
        exit(1);
    }
    i__1 = data_size - 1;
    i__2 = 0;
    i__ = 0;
}