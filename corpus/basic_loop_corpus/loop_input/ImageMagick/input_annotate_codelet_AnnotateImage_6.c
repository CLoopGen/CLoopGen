#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char *p;
char **textlist;
size_t number_lines;
ssize_t i;

static char *input_buffer;
static size_t total_size = 1 << 20; // 1MB data

void init_vars() {
    input_buffer = (char*)calloc(total_size, sizeof(char));
    if (!input_buffer) exit(1);

    size_t pos = 0;
    number_lines = 0;
    const size_t max_lines = total_size / 8;

    textlist = (char**)calloc(max_lines, sizeof(char*));
    if (!textlist) exit(1);

    while (pos < total_size - 10) {
        textlist[number_lines] = &input_buffer[pos];
        number_lines++;

        size_t line_len = rand() % 70 + 2;
        size_t end = pos + line_len;
        if (end >= total_size - 10) break;

        for (size_t j = pos; j < end - 1; j++) {
            input_buffer[j] = (rand() % 50) + 'A';
        }

        if (rand() % 5 == 0) {
            input_buffer[end - 1] = '\r';
            input_buffer[end] = '\n';
            pos = end + 1;
        } else {
            input_buffer[end - 1] = '\n';
            pos = end;
        }
    }

    p = textlist[0];
}