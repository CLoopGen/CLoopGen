#include <stdint.h>
#include <stddef.h>

uint16_t cnts[256];
uint16_t freqs[512];
int b;
uint32_t a;

void init_vars() {
    for (int i = 0; i < 256; i++) {
        cnts[i] = (uint16_t)(i * 7 + 1); // Non-zero pattern to simulate realistic data
    }
    for (int i = 0; i < 512; i++) {
        freqs[i] = 0;
    }
    b = 0;
    a = 0;
}