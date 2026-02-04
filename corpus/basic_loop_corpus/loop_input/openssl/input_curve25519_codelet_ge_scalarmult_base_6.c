#include <stdint.h>

uint8_t *a;
signed char e[64];
int i;

static uint8_t a_data[32];

void init_vars() {
    a = a_data;
    for (int j = 0; j < 32; ++j) {
        a[j] = (uint8_t)(j * 7 + 3); // Arbitrary initialization
    }
    for (int j = 0; j < 64; ++j) {
        e[j] = 0;
    }
    i = 0;
}