#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *message;
char *p;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    message = (char*)malloc(data_size);
    if (!message) {
        exit(1);
    }

    // Initialize with printable characters and some newlines
    for (size_t i = 0; i < data_size - 1; i++) {
        if (rand() % 32 == 0) {
            message[i] = '\n';
        } else {
            message[i] = 'A' + (i % 26);
        }
    }
    message[data_size - 1] = '\x00'; // null-terminate
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}