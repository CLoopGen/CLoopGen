#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t count = (1 << 20); // 1MB worth of elements, assuming bytes
size_t bits_per_pixel;
size_t one = 1;

void init_vars() {
    // No additional initialization needed; scalars are already defined at file scope
}