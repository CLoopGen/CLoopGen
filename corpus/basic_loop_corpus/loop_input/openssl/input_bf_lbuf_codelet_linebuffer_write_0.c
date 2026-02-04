#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *in;
int inl;
char *p;
char c;

static char *buffer;

void init_vars() {
    size_t data_size = 512 * 1024; // 512 KB of input data
    buffer = (char *)malloc(data_size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Fill with non-newline characters for most of the buffer
    memset(buffer, 'A', data_size - 1);
    // Place a newline at the end to terminate the loop
    buffer[data_size - 1] = '\n';

    in = buffer;
    inl = data_size;
    p = in;
    c = '\0';
}