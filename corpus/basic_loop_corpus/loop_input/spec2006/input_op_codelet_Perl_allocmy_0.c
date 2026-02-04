#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *name;
char *p;

static char *buffer;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB
    buffer = (char *)calloc(data_size, sizeof(char));
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    memset(buffer, 'A', data_size - 1);
    buffer[data_size - 1] = '\0';

    name = buffer;
    p = buffer + data_size - 2; // Ensure p - name > 2 initially and *p and *(p-1) are valid
}