#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double coeff[100];

int ii;

void init_vars() {
    // No additional initialization needed beyond zeroing coeff in loop
    // Array size is fixed at 100, so no dynamic allocation required
    // Variables are already at file scope and will be initialized to zero by default
}