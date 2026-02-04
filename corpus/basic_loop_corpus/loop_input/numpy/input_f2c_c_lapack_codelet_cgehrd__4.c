#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/time.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *ihi;
singlecomplex *tau;
integer i__1;
integer i__2;
integer i__;

void init_vars() {
    static int initialized = 0;
    if (initialized) return;
    initialized = 1;

    const long data_size = 64 * 1024 * 1024; 
    tau = (singlecomplex*)aligned_alloc(32, data_size * sizeof(singlecomplex));
    if (!tau) exit(1);

    for (long i = 0; i < data_size; ++i) {
        tau[i].r = 0.0f;
        tau[i].i = 0.0f;
    }

    ihi = (integer*)aligned_alloc(32, sizeof(integer));
    if (!ihi) exit(1);
    *ihi = 1;

    i__1 = data_size - 1;
    i__2 = 0;
    i__ = 0;
}