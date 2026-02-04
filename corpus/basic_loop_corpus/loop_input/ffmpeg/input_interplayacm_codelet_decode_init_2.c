#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int mul_2x11[121];
int x1;
int x2;

void init_vars() {
    // No dynamic initialization needed; all variables are global and zero-initialized by default.
    // The loop uses fixed bounds (11x11), so no setup is required for correct memory access.
}