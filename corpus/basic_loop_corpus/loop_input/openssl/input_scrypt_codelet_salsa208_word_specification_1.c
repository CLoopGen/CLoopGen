#include <inttypes.h>

uint32_t inout[16];
int i;
uint32_t x[16];

void init_vars() {
    for (i = 0; i < 16; ++i) {
        inout[i] = i * 2;
        x[i] = i + 1;
    }
}