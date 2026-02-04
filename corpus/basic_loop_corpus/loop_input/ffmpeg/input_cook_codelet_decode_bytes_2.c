#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int bytes;
int i;
uint32_t c;
uint32_t *buf;
uint32_t *obuf;

void init_vars() {
    // Target approximately 0.01 seconds runtime on modern CPU
    // Assume ~1-2 GB/s for simple XOR loop -> use 16 MB of data as reasonable middle ground
    size_t data_size = 16 << 20; // 16 MiB
    bytes = data_size;

    // Allocate buffers aligned to 4-byte boundaries (natural for uint32_t)
    buf = aligned_alloc(32, data_size);
    obuf = aligned_alloc(32, data_size);

    if (!buf || !obuf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffer contents
    for (size_t j = 0; j < data_size / sizeof(uint32_t); j++) {
        buf[j] = (uint32_t)(j ^ 0xDEADBEEF);
    }

    // Initialize constant used in loop
    c = 0xCAFEBABE;

    // Ensure obuf is accessible and i is initialized by loop, no need to pre-initialize obuf values
}

// Reset state if needed in future runs
void cleanup() {
    if (buf) free(buf);
    if (obuf) free(obuf);
}