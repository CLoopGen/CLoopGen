#include <stdint.h>
#include <stddef.h>

uint64_t c;
uint64_t n[59];
int i;

void init_vars() {
    c = 0x123456789ABCDEF0ULL;
    for (int j = 0; j < 59; ++j) {
        n[j] = 0xABCDEF0123456789ULL ^ j;
    }
    i = 58;
}