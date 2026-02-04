#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t OPJ_UINT32;

OPJ_UINT32 a;
OPJ_UINT32 l;

void init_vars() {
    a = 1U << 24;  // Large enough to make loop run many iterations: ~24 shifts
    l = 0;
}