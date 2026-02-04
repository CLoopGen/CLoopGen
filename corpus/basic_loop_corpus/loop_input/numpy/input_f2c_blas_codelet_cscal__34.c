#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *ca;
singlecomplex *cx;
integer i__1;
integer i__2;
integer i__3;
singlecomplex q__1;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M floats = ~256MB for complex pairs
    cx = (singlecomplex*)aligned_alloc(32, data_size * sizeof(singlecomplex));
    
    if (!cx) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        cx[idx].r = (real)(drand48() * 2.0 - 1.0);
        cx[idx].i = (real)(drand48() * 2.0 - 1.0);
    }

    ca = (singlecomplex*)aligned_alloc(32, sizeof(singlecomplex));
    if (!ca) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    ca->r = (real)(drand48() * 2.0 - 1.0);
    ca->i = (real)(drand48() * 2.0 - 1.0);

    i__2 = (integer)(data_size * 0.75); 

    i__1 = 0;
    i__3 = 0;
    i__ = 0;
    q__1.r = 0.0f;
    q__1.i = 0.0f;
}