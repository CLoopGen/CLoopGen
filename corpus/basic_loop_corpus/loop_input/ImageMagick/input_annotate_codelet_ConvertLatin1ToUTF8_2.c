#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

unsigned char *restrict content;
unsigned char *restrict p;
size_t length;

static unsigned char *data_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPU
    data_buffer = (unsigned char *)aligned_alloc(32, data_size);
    if (!data_buffer) exit(1);

    for (size_t i = 0; i < data_size - 1; i++) {
        data_buffer[i] = rand() % 256;
    }
    data_buffer[data_size - 1] = '\x00'; 

    content = data_buffer;
    p = content;
    length = 0;
}