#include <stdint.h>
#include <stdlib.h>

uint8_t *buf1;
uint32_t state;
int k;

void init_vars() {
    state = 123456789; // Initialize state with a non-zero seed
    buf1 = (uint8_t*)malloc(320 * 240 * sizeof(uint8_t));
    if (!buf1) {
        exit(1);
    }
    k = 0; // Will be properly set by loop, but initialize for safety
}