#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *internal_s;
static const size_t data_size = 134217728; // 128 MB

void init_vars() {
    internal_s = (char *)malloc(data_size);
    if (!internal_s) {
        exit(1);
    }

    size_t fill_len = data_size - 1;
    memset(internal_s, 'x', fill_len);
    internal_s[fill_len] = '\0';

    s = internal_s;
    len = data_size;
    i = 0;
}