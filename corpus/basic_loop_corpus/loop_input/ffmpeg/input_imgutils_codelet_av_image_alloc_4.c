#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int linesizes[4] = {1024, 2048, 512, 4096};
int align = 64;
int i;

void init_vars() {
    // No additional dynamic initialization needed; all variables are statically initialized
}