#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024)

char start_color[DATA_SIZE];
char *p;

void init_vars() {
    char *data = start_color;
    size_t pos = 0;

    while (pos < DATA_SIZE - 100) {
        int segment_type = rand() % 5;
        switch (segment_type) {
            case 0:
                data[pos++] = '(';
                for (int j = 0; j < 10 && pos < DATA_SIZE - 1; j++) {
                    data[pos++] = 'a' + (rand() % 26);
                }
                if (pos < DATA_SIZE) data[pos++] = ')';
                break;
            default:
                data[pos++] = 'A' + (rand() % 26);
                break;
        }
    }

    while (pos < DATA_SIZE - 1) {
        data[pos++] = 'X';
    }

    data[DATA_SIZE - 1] = '\0';

    p = start_color;
}