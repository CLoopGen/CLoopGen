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
    size_t data_size = 128 << 20; // 128 MB
    buffer = (char *)malloc(data_size);
    if (!buffer) {
        exit(1);
    }

    // Fill with non-zero bytes to simulate a string that ends at 75% of the buffer
    memset(buffer, 'x', data_size);
    buffer[(3 * data_size) / 4] = '\0'; // null-terminator inside buffer

    s = buffer;
    len = data_size;
    i = 0;
}