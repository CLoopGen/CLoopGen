#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

short *extrema;
ssize_t i;

static short extrema_data[131072]; // 131072 * sizeof(short) = 256KB of data

void init_vars() {
    extrema = extrema_data;
    i = 0;
}