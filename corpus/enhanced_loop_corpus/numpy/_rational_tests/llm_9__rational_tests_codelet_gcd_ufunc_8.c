#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp is0;
extern npy_intp is1;
extern npy_intp os;
extern npy_intp n;
extern char *i0;
extern char *i1;
extern char *o;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const npy_intp unroll_factor = 4;
    npy_intp trip_count = n / unroll_factor;
    for (k = 0; k < trip_count; k++) {
        i0 += is0; i0 += is0; i0 += is0; i0 += is0;
        i1 += is1; i1 += is1; i1 += is1; i1 += is1;
        o += os; o += os; o += os; o += os;
    }
    // Adjust k to reflect actual iteration count
    k = trip_count * unroll_factor;
    while (k < n) {  // Note: using while only for cleanup, not primary loop
        i0 += is0;
        i1 += is1;
        o += os;
        k++;
    }
}
