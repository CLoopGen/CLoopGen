#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int planes[4] = {10, 20, 30, 40};
int ret;

void init_vars() {
    // No dynamic initialization needed; all variables are statically defined
    // and within bounds for the loop which runs from 0 to 3.
}