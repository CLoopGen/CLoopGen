#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t ord;
double pc[1 << 20]; // 8MB array (assuming double is 8 bytes)
double *ordp2coeff;
size_t i;
int s;

void init_vars() {
    ord = (1 << 20) - 1; // ensures pc[i] access up to ord is safe
    ordp2coeff = &pc[0];
    i = 0;
    s = 1;
}