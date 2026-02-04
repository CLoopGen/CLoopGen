#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int planes[4] = {10, 20, 30, 40};
int ret;

void init_vars() {
    // No dynamic initialization required; all variables are statically defined
    // The array size is fixed at 4, so no extra allocation needed
    // Initial values are set at declaration for planes[]
    // 'i' and 'ret' are used as accumulators in the loop and start at 0
}