#include <stdint.h>
#include <stdlib.h>

int i;
uint32_t *mt;
int k;

void init_vars() {
    mt = (uint32_t*)aligned_alloc(16, 624 * sizeof(uint32_t));
    if (!mt) exit(1);
    for (int idx = 0; idx < 624; idx++) {
        mt[idx] = (uint32_t)(idx * 7919);
    }
    i = 1;
}