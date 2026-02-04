#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t min = 100;
size_t max = 1000;
size_t steps = 8;

unsigned char codes[8];

ssize_t i;

void init_vars() {
    min = 100;
    max = 1000;
    steps = 8;
    for (size_t idx = 0; idx < 8; ++idx) {
        codes[idx] = (unsigned char)(idx * 31);
    }
    i = 0;
}