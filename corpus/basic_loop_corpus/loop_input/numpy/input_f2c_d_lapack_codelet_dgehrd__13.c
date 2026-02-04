#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef int integer;
typedef double doublereal;

integer *ihi;
doublereal *tau;
integer i__1;
integer i__;

static integer static_ihi;
static doublereal *static_tau;
static integer static_i__1;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 million doubles = 512 MB
    static_tau = (doublereal *)calloc(data_size, sizeof(doublereal));
    if (!static_tau) exit(1);

    static_ihi = 1;
    static_i__1 = data_size - 1;

    ihi = &static_ihi;
    tau = static_tau;
    i__1 = static_i__1;
}