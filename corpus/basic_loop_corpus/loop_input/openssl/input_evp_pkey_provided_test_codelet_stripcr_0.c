#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *buf;
size_t *len;
size_t i;
char *curr;
char *writ;

void init_vars() {
    const size_t data_size = 512 * 1024;
    buf = (char *)malloc(data_size);
    if (!buf) {
        exit(1);
    }

    len = (size_t *)malloc(sizeof(size_t));
    if (!len) {
        free(buf);
        exit(1);
    }

    *len = data_size;

    for (size_t idx = 0; idx < data_size; idx++) {
        buf[idx] = (rand() % 50) == 0 ? '\r' : 'A' + (rand() % 26);
    }

    i = 0;
    curr = NULL;
    writ = NULL;
}