#include <stdint.h>
#include <stdlib.h>

unsigned char *B;
uint64_t r;
uint32_t *X;
unsigned char *pB;
uint64_t i;

void init_vars() {
    r = 8192; // This results in 32 * r = 262144 iterations, writing 4 bytes per iteration -> 1MB output

    X = (uint32_t*)malloc(32 * r * sizeof(uint32_t));
    B = (unsigned char*)malloc(4 * 32 * r * sizeof(unsigned char)); // 4 bytes written per X element

    for (i = 0; i < 32 * r; i++) {
        X[i] = (uint32_t)(0xABCDEF00 | (i & 0xFF));
    }

    pB = B; // Initialize pB to point to start of B buffer
}