#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *name;

static char *buffer = NULL;
static size_t buffer_size = 1024 * 1024; // 1MB

void init_vars() {
    if (buffer == NULL) {
        buffer = (char *)calloc(buffer_size, sizeof(char));
        if (buffer == NULL) {
            exit(1);
        }
        for (size_t i = 0; i < buffer_size - 1; i++) {
            buffer[i] = ' ';
        }
        buffer[buffer_size - 1] = 'A'; 
    }
    name = buffer;
}