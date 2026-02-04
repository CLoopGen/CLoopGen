#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int num_pixels;
int i;

void init_vars() {
    num_pixels = 10000000; // Adjusted for ~0.01 sec runtime
}