#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double P[20];
int i;

void init_vars() {
    // No additional initialization needed beyond zeroing or default static init
    // P and i are already at file scope and will be initialized to zero by default
    // The loop uses fixed bounds (0 to 19) so no dynamic sizing is required
}