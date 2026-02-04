#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *linebuf;
int flags;
int len;
char *p;
char c;
int is_eol;

void init_vars() {
    const size_t data_size = 512 * 1024;
    linebuf = (char*)malloc(data_size);
    if (!linebuf) {
        exit(1);
    }

    len = data_size;
    p = linebuf + len - 1;

    for (int i = 0; i < data_size; i++) {
        linebuf[i] = ' ';
    }
    linebuf[data_size - 1] = '\n';
    linebuf[data_size - 2] = '\r';

    flags = 524288;
    c = 0;
    is_eol = 0;
}