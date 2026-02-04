#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *res;
char *start;
char *end;
int i;

static char *buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime
    buffer = (char *)malloc(data_size);
    if (!buffer) {
        exit(1);
    }

    // Fill with mostly 'X', add '(' near the beginning, ')' near the end
    memset(buffer, 'X', data_size - 1);
    buffer[data_size - 1] = '\0';

    size_t open_pos = data_size / 8;
    size_t close_pos = data_size / 2;

    buffer[open_pos] = '(';
    buffer[close_pos] = ')';

    res = buffer;
    start = NULL;
    end = NULL;
    i = 0;
}