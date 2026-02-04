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
        if (!buffer) {
            exit(1);
        }
    }

    char *data = buffer;
    
    size_t pos = 0;
    while (pos < data_size - 100) {
        int choice = rand() % 10;
        if (choice < 7) {
            data[pos++] = 'a' + (rand() % 26);
        } else if (choice < 9) {
            data[pos++] = '(';
            int len = 1 + rand() % 15;
            for (int i = 0; i < len; i++) {
                data[pos++] = 'a' + (rand() % 26);
            }
            data[pos++] = ')';
        } else {
            data[pos++] = '-';
        }
    }

    if (pos >= data_size) pos = data_size - 1;
    data[pos] = '\0';

    memcpy(start_color, data, sizeof(start_color));
    p = start_color;

    srand(time(NULL));
    for (int i = 0; i < 1000 + (rand() % 1000); i++) {
        rand();
    }
}