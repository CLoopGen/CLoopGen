#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int tmsize_t;

tmsize_t i;
tmsize_t n = 10000000; // Sufficiently large to take ~0.01s

void init_vars() {
    i = 0;
    n = 10000000;
}