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

singlecomplex *y;
integer i__1;
integer i__2;
integer i__;

void init_vars() {
    i__1 = 65536000;  // Size chosen to make loop run ~0.01s (approx 65M iterations)
    y = (singlecomplex*)calloc(i__1 + 1, sizeof(singlecomplex));
    if (!y) {
        exit(1);
    }
}