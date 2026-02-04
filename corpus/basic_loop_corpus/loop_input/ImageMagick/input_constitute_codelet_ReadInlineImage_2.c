#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *content;
char *p;

static char *buffer;
static size_t data_size = 64 * 1024 * 1024; // 64 MB for sufficient runtime (~0.01 sec)

void init_vars() {
    if (buffer != NULL) return; // Prevent multiple initializations

    buffer = (char*)malloc(data_size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Fill buffer with non-comma, non-null characters except near the end
    memset(buffer, 'A', data_size - 256);
    // Place a comma at a predictable position to stop the loop
    buffer[data_size - 256] = ',';
    // Null terminate just in case
    buffer[data_size - 1] = '\x00';

    content = buffer;
    p = content;
}

__attribute__((constructor))
void auto_init() {
    init_vars();
}