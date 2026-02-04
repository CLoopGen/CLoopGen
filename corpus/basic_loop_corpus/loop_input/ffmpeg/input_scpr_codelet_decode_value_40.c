#include <stdint.h>
#include <stdlib.h>

uint32_t *cnt;
uint32_t maxc;
uint32_t totfr;
int i;

void init_vars() {
    maxc = 16777216; // 64 MB / sizeof(uint32_t) = 16M elements
    cnt = (uint32_t*)aligned_alloc(32, maxc * sizeof(uint32_t));
    totfr = 0;
    i = 0;

    for (uint32_t idx = 0; idx < maxc; idx++) {
        cnt[idx] = (idx * 78901) & 0xFFFFF; // arbitrary non-zero initial values
    }
}