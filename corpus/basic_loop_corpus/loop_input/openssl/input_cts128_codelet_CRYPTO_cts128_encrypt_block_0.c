#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *in;
unsigned char ivec[16];
size_t residue;
size_t n;

void init_vars() {
    const size_t data_size = 512 * 1024; // 512 KB for ~0.01 sec runtime estimate

    in = (unsigned char *)malloc(data_size);
    if (!in) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    residue = 16; // Ensure we don't exceed ivec bounds (size 16)

    // Initialize 'in' with predictable non-zero data
    for (size_t i = 0; i < data_size; ++i) {
        in[i] = (unsigned char)(i & 0xFF);
    }

    // Initialize ivec with known values
    for (int i = 0; i < 16; ++i) {
        ivec[i] = (unsigned char)((i + 1) * 0x11);
    }
}