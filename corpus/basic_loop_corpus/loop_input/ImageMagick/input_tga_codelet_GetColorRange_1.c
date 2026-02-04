#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char start_color[4096];
char *p;

void init_vars() {
    size_t data_size = 1 << 20;
    static char *buffer = NULL;

    if (buffer == NULL) {
        buffer = aligned_alloc(4096, data_size);
        if (!buffer) exit(1);
    }

    char *data = buffer;
    size_t pos = 0;

    while (pos < data_size - 50) {
        int r = rand() % 100;
        if (r < 70) {
            data[pos++] = 'a' + (rand() % 26);
        } else if (r < 85) {
            data[pos++] = '(';
            int len = 1 + (rand() % 10);
            for (int i = 0; i < len && pos < data_size - 1; i++) {
                data[pos++] = 'a' + (rand() % 26);
            }
            if (pos < data_size) data[pos++] = ')';
        } else if (r < 95) {
            data[pos++] = '-';
        } else {
            data[pos++] = ' ';
        }
    }

    if (pos < data_size) {
        data[pos++] = '-';
    }
    if (pos < data_size) {
        data[pos] = '\0';
    }

    memcpy(start_color, data, sizeof(start_color));

    p = start_color;
}