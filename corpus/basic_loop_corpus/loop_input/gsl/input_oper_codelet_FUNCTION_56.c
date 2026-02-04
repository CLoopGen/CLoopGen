#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t loop_lim;
size_t i;

void init_vars() {
    loop_lim = 100000000; // Adjust to target ~0.01 seconds runtime on modern CPU
}