#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *buffer;

void init_vars() {
    size_t data_size = 64 << 20; // 64 MB to target ~0.01 sec on modern CPU
    buffer = (char *)malloc(data_size);
    if (!buffer) {
        exit(1);
    }

    // Fill with non-zero bytes to simulate string data
    memset(buffer, 'x', data_size - 1);
    // Null-terminate at a random position near the end to ensure loop runs long
    size_t null_pos = data_size - 1 - (rand() % 65536);
    buffer[null_pos] = '\0';

    s = buffer;
    len = data_size;
}
// Note: The actual loop function is defined externally and should be linked in.