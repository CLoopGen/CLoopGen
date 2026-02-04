#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef unsigned long UV;

char *s;
int i;
UV mask;
UV aligned;

char **PL_origenviron;

static char **env_buffer;
static char *data_block;
static size_t data_size = 1 << 20; // 1MB of data

void init_vars() {
    // Allocate a large block of memory for string storage
    data_block = calloc(data_size, 1);
    if (!data_block) exit(1);

    // Fill with non-zero bytes to simulate valid strings
    memset(data_block, 'A', data_size - 1);
    // Null-terminate each 64-byte segment to form strings
    for (size_t pos = 63; pos < data_size - 1; pos += 64) {
        data_block[pos] = '\0';
    }

    // Allocate environment-like pointer array
    size_t num_ptrs = 10000;
    env_buffer = malloc((num_ptrs + 1) * sizeof(char*));
    if (!env_buffer) exit(1);

    // Initialize pointers to point into the data block at 64-byte intervals
    for (size_t idx = 0; idx < num_ptrs; idx++) {
        env_buffer[idx] = &data_block[idx * 64];
    }
    env_buffer[num_ptrs] = NULL; // null terminator as required by loop condition

    // Assign to external variable
    PL_origenviron = env_buffer;

    // Initialize s to point inside the data block
    s = &data_block[32];

    // Set mask to align to 8-byte boundary: e.g., 0xFFFFFFFFFFFFFFF8ULL
    mask = ~(UV)(7);

    // Set aligned to 1 to enable the alignment check branch
    aligned = 1;

    // Initialize loop index
    i = 1;
}