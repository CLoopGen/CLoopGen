#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned char *dest;
int dest_index;
int count;
int src_pos;
int i;

static unsigned char *buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec on modern CPU
    buffer = (unsigned char *)calloc(data_size, sizeof(unsigned char));
    if (!buffer) {
        exit(1);
    }

    dest = buffer;
    dest_index = 0;
    src_pos = 32 * 1024 * 1024; // source starts at halfway point
    count = 32 * 1024 * 1024;   // copy 32 million bytes

    // Ensure src_pos + count does not exceed buffer size
    if (src_pos + count > data_size) {
        exit(1);
    }
}