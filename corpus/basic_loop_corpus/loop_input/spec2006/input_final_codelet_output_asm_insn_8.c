#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern int dialect_number;
extern char *p;
extern int i;

int dialect_number = 1000000;
char *p;
int i;

static char data_buffer[1 << 20]; // 1MB buffer

void init_vars() {
    const size_t buf_size = sizeof(data_buffer);
    size_t pos = 0;
    srand((unsigned int)time(NULL));

    while (pos < buf_size - 100) {
        int len = rand() % 50 + 1;
        for (int j = 0; j < len; j++) {
            if (pos >= buf_size - 2) break;
            data_buffer[pos++] = 'a' + (rand() % 26);
        }
        if (pos >= buf_size - 2) break;
        if (rand() % 5 == 0) {
            data_buffer[pos++] = '}';
            break;
        } else {
            data_buffer[pos++] = '|';
        }
    }
    if (pos < buf_size) {
        data_buffer[pos] = '\0';
    }

    p = data_buffer;
}