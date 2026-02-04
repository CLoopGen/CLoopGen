#include <stdint.h>
#include <stdlib.h>

uint16_t s[16];
int i;

void init_vars() {
    for (int j = 0; j < 16; ++j) {
        s[j] = rand() & 0xFFFF;
    }
    i = 0;
}