#include <stdlib.h>
#include <stdint.h>

uint32_t *lut;

void init_vars() {
    lut = (uint32_t *)aligned_alloc(32, 128);
    if (!lut) exit(1);
}

__attribute__((destructor))
static void cleanup() {
    free(lut);
}