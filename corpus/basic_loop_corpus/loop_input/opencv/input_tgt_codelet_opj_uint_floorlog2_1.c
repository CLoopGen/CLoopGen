#include <stdint.h>

uint32_t a;
uint32_t l;

void init_vars() {
    a = 0x80000000u;  // Initialize 'a' to a large value so the loop runs many iterations
    l = 0;
}