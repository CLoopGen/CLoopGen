#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int *in;
int i;

static unsigned int in_data[131072]; // 512 KB of data (131072 elements * 4 bytes)

void init_vars() {
    in = in_data;
}