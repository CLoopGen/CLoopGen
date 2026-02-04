#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

char *seq;
static char *seq_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    seq_buffer = (char *)malloc(data_size);
    if (!seq_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize with random DNA-like sequence
    const char alphabet[] = "ACGTacgt";
    size_t i;
    for (i = 0; i < data_size - 1; i++) {
        seq_buffer[i] = alphabet[rand() % 8];
    }
    seq_buffer[data_size - 1] = '\x00'; // Null terminate

    seq = seq_buffer;
}

__attribute__((destructor)) void cleanup() {
    free(seq_buffer);
}