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
static size_t internal_len;

void init_vars() {
    internal_len = 64 * 1024 * 1024;
    internal_s = (char*)malloc(internal_len);
    if (!internal_s) {
        exit(1);
    }
    
    for (size_t idx = 0; idx < internal_len - 1; idx++) {
        internal_s[idx] = 'a' + (idx % 26);
    }
    internal_s[internal_len - 1] = '\0';

    s = internal_s;
    len = internal_len;
    i = 0;
}