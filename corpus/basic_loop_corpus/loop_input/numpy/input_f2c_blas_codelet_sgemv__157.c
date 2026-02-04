#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *beta;
real *y;
integer i__1;
integer i__;

void init_vars() {
    i__1 = 1 << 20;  

    y = (real *)aligned_alloc(32, (i__1 + 1) * sizeof(real));
    if (!y) exit(1);

    for (int i = 1; i <= i__1; ++i) {
        y[i] = (real)(i & 0xFF);
    }

    beta = (real *)aligned_alloc(32, sizeof(real));
    if (!beta) exit(1);
    *beta = 2.5f;
}

void loop(); 

__attribute__((constructor)) 
void auto_init() {
    init_vars();
}