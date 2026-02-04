#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *nextchar;
char *nameend;

static char data_buffer[1 << 24]; // 16 MB buffer

void init_vars() {
    size_t len = sizeof(data_buffer) - 1;
    memset(data_buffer, 'a', len);
    data_buffer[len] = '\0';

    size_t equal_pos = len / 2;
    data_buffer[equal_pos] = '=';

    nextchar = data_buffer;
    nameend = NULL;
}