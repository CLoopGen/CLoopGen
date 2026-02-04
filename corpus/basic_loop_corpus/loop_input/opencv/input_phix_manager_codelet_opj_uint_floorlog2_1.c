#include <stdint.h>

uint32_t a;
uint32_t l;

void init_vars() {
    a = 1U << 24;  // Set 'a' to 2^24 so that the loop runs about 24 iterations, which is sufficient to reach ~0.01s when combined with repeated calls if needed
    l = 0;
}