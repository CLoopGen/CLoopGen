#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *filename;
int len;
char *p;
char *q;

static char *buffer;

void init_vars() {
    size_t data_size = 64 << 20; // 64 MB to target ~0.01 sec runtime
    buffer = (char *)malloc(data_size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize with mostly normal characters, some spaces/tabs and backslashes for edge cases
    for (size_t i = 0; i < data_size - 1; i++) {
        int r = rand() % 100;
        if (r < 5) {
            buffer[i] = ' ';
        } else if (r < 10) {
            buffer[i] = '\t';
        } else if (r < 15 && i > 0 && buffer[i-1] == '\\') {
            // Create sequences of backslashes
            buffer[i] = '\\';
        } else if (r < 20) {
            buffer[i] = '\\';
        } else if (r < 25) {
            buffer[i] = '$';
        } else {
            buffer[i] = 'a' + (rand() % 26);
        }
    }
    buffer[data_size - 1] = '\0'; // Ensure null terminator

    filename = buffer;
    len = 0;
    p = NULL;
    q = NULL;
}