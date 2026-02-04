#include <stdint.h>

#include <stdlib.h>
#include <stddef.h>

typedef uint32_t OPJ_UINT32;

OPJ_UINT32 a;
OPJ_UINT32 l;

void init_vars() {
    a = 1U << 24;  // Initialize 'a' to a large value so the loop runs for ~24 iterations, taking around 0.01 seconds
    l = 0;
}