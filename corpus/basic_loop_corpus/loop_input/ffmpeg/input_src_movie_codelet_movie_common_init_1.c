#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int nb_streams;
char *stream_specs;
char *cursor;

void init_vars() {
    nb_streams = 0;

    size_t data_size = 64 * 1024 * 1024;
    stream_specs = (char*)malloc(data_size);
    if (!stream_specs) exit(1);

    for (size_t i = 0; i < data_size - 1; i++) {
        stream_specs[i] = (rand() % 16) == 0 ? '+' : 'a';
    }
    stream_specs[data_size - 1] = '\0';
}