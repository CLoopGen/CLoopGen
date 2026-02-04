#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *p;
char *text;
size_t number_lines;

static char *buffer;
static size_t buffer_size = 1 << 24; // 16 MB of data

void init_vars() {
    buffer = (char *)malloc(buffer_size);
    if (!buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    size_t i = 0;
    while (i < buffer_size - 1) {
        int rand_char = rand() % 100;
        if (rand_char < 5) {
            buffer[i++] = '\n';
        } else {
            buffer[i++] = 'a' + (rand() % 26);
        }
    }
    buffer[buffer_size - 1] = '\x00';

    p = buffer;
    text = buffer;
    number_lines = 0;
}