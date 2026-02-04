#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *dst;
char *src;
size_t size;
size_t l;

static char src_buffer[1024 * 128]; // 128KB source buffer
static char dst_buffer[1024 * 128]; // 128KB destination buffer

void init_vars() {
    size = sizeof(src_buffer);
    l = 0;

    // Initialize src_buffer with non-zero data, null-terminated at the end
    memset(src_buffer, 'A', sizeof(src_buffer) - 1);
    src_buffer[sizeof(src_buffer) - 1] = '\0';

    // Point src to the beginning of src_buffer
    src = src_buffer;

    // Point dst to the beginning of dst_buffer
    dst = dst_buffer;
}