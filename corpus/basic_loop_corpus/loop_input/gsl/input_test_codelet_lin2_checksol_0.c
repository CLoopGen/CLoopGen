#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double x[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
size_t i = 0;
double sum = 0.0;

void init_vars() {
    // No dynamic initialization needed; static initializers suffice
    // Array size is fixed at 5 to match loop bound
    // All variables are already properly initialized at file scope
}