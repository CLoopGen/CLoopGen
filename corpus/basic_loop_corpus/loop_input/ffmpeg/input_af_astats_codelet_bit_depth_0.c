#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint64_t mask;
unsigned int result;

void init_vars() {
    result = 10000000;
    mask = UINT64_C(0xFFFFFFFFFFFFFFFE);
}