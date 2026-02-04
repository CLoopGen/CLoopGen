#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double count[10][10];
int i;
int j;

void init_vars() {
    // No dynamic initialization needed; static arrays are zero-initialized by default
    // Loop bounds are fixed (0 to 9) so no risk of out-of-bounds access
}