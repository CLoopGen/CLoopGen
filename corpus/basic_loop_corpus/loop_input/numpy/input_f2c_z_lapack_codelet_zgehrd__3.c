#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

integer i__1;
integer i__2;
integer i__;
doublecomplex *tau;

void init_vars() {
    i__1 = 134217728;  // 134M elements ~ 2GB for doublecomplex (each 16 bytes), loop runs approx 0.01s on modern CPU
    tau = (doublecomplex*)calloc(i__1 + 1, sizeof(doublecomplex));
    if (!tau) {
        exit(1);
    }
}