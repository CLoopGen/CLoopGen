#include <stdint.h>
#include <stdlib.h>

int mti;
uint32_t *mt;

void init_vars() {
    mt = (uint32_t *)aligned_alloc(16, 624 * sizeof(uint32_t));
    if (!mt) exit(1);
    for (int i = 0; i < 624; i++) {
        mt[i] = 0x12345678UL;
    }
}