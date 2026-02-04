#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x_out;
int x_out_max;

void init_vars() {
    x_out_max = 10000000; // Adjusted for ~0.01 seconds runtime
}