#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t OPJ_UINT32;

OPJ_UINT32 a;
OPJ_UINT32 l;

void init_vars() {
    a = 0x80000000U; // Large value to ensure the loop runs many times (31 iterations)
    l = 0;
}