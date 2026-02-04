#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *type;
char *original_type;
size_t data_size = 1 << 20; // 1MB of data

void init_vars() {
    if (original_type) {
        free(original_type);
    }
    original_type = malloc(data_size);
    if (!original_type) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    memset(original_type, ' ', data_size - 1);
    original_type[data_size - 1] = 'A';

    type = original_type;
}

__attribute__((constructor)) void setup() {
    init_vars();
}

__attribute__((destructor)) void cleanup() {
    free(original_type);
    original_type = NULL;
    type = NULL;
}