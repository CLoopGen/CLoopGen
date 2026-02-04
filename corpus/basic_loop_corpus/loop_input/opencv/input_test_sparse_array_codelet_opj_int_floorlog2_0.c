#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;

OPJ_INT32 a;
OPJ_INT32 l;

void init_vars() {
    a = 1 << 24;
    l = 0;
}