#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int *in;
int i;

static unsigned int in_array[1 << 20]; // 4MB array (about 1M elements)

void init_vars() {
    in = in_array;
}