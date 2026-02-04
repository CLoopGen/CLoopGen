#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char *s;
size_t len;
size_t i;

static char *internal_s;
static size_t internal_len = 67108864; // ~64MB to ensure ~0.01 sec runtime on modern CPU

void init_vars() {
    internal_s = (char*)calloc(internal_len, sizeof(char));
    if (!internal_s) {
        exit(1);
    }
    for (size_t idx = 0; idx < internal_len - 1; idx++) {
        internal_s[idx] = 'x';
    }
    internal_s[internal_len - 1] = '\0';

    s = internal_s;
    len = internal_len;
    i = 0;
}