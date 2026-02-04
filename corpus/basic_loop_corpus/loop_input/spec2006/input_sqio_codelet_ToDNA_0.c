#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *seq;

static char *seq_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024;
    seq_buffer = (char *)malloc(data_size);
    if (!seq_buffer) {
        exit(1);
    }
    for (size_t i = 0; i < data_size - 1; i++) {
        int r = rand() % 32;
        if (r == 0)
            seq_buffer[i] = 'U';
        else if (r == 1)
            seq_buffer[i] = 'u';
        else
            seq_buffer[i] = 'A' + (rand() % 26);
    }
    seq_buffer[data_size - 1] = '\x00';

    seq = seq_buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(seq_buffer);
}