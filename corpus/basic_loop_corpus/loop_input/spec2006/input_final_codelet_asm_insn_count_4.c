#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

char *template;
int count;

static char *buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime on modern CPU
    buffer = (char *)malloc(data_size);
    if (!buffer) {
        exit(1);
    }

    size_t i;
    for (i = 0; i < data_size - 1; i++) {
        int r = rand() % 100;
        if (r < 5) {
            buffer[i] = ';';
        } else if (r < 10) {
            buffer[i] = '\n';
        } else {
            buffer[i] = 'A' + (rand() % 26);
        }
    }
    buffer[data_size - 1] = '\0';

    template = buffer;
    count = 0;
}