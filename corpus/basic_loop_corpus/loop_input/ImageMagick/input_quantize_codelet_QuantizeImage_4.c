#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t depth;
size_t colors;

void init_vars() {
    colors = (size_t)1 << 62;
}