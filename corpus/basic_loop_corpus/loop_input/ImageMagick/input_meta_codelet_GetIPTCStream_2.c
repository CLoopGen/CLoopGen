#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t info_length;
size_t tag_length;
unsigned char *p;
ssize_t i;

static unsigned char *data_buffer;
static size_t data_size;

void init_vars() {
    data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    data_buffer = (unsigned char *)malloc(data_size);
    if (!data_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        data_buffer[idx] = rand() & 0xFF;
    }

    p = data_buffer;
    length = data_size;
    info_length = 0;
    tag_length = 0x12345678; // arbitrary initial value to allow bit shifting
    i = 0;
}