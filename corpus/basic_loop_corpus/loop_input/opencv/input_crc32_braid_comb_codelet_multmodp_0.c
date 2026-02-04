#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t a = 0;
uint32_t b = 1;
uint32_t m = (uint32_t)1 << 31;
uint32_t p = 0;

void init_vars() {
    a = 0x80000000U;
    b = 0x80000000U;
    m = 1U << 31;
    p = 0;
}