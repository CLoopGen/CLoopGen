#include <stdint.h>
#include <stdlib.h>
#include <string.h>

unsigned char *B;
uint64_t r;
uint32_t *V;
unsigned char *pB;
uint32_t *pV;
uint64_t i;

void init_vars() {
    // Set data size to achieve ~0.01 seconds runtime
    // Each iteration reads 4 bytes from B and writes 1 uint32_t to V
    // Aim for approximately 512KB of input data (r = 32768 gives 32*r = 1M iterations, 4MB output)
    r = 32768;

    // Allocate B with sufficient size: each iteration consumes 4 bytes, total 4 * 32 * r
    size_t B_size = 4 * 32 * r;
    unsigned char *temp_B = malloc(B_size);
    if (!temp_B) exit(1);

    // Initialize B with dummy data
    for (size_t idx = 0; idx < B_size; idx++) {
        temp_B[idx] = (unsigned char)(idx & 0xFF);
    }

    // Allocate V: 32 * r elements of uint32_t
    size_t V_size = 32 * r;
    uint32_t *temp_V = malloc(V_size * sizeof(uint32_t));
    if (!temp_V) {
        free(temp_B);
        exit(1);
    }

    // Assign global pointers
    B = temp_B;
    V = temp_V;
}