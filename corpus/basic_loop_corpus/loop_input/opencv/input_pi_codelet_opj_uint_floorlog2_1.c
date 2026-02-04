#include <stdint.h>

uint32_t a;
uint32_t l;

void init_vars() {
    a = 0x80000000u;  // Large value to ensure loop runs many iterations
    l = 0;
}