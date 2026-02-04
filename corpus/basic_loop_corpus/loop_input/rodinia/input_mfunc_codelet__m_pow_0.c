#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int p;
int max_bit;

void init_vars() {
    p = 1 << 20;
    max_bit = 0;
}