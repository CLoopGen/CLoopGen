#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

static char *internal_s;
static size_t internal_len = 134217728; // 128 MB

void init_vars() {
    internal_s = (char*)malloc(internal_len);
    if (!internal_s) {
        exit(1);
    }
    
    memset(internal_s, 'x', internal_len - 1);
    internal_s[internal_len - 1] = '\0';

    s = internal_s;
    len = internal_len;
    i = 0;
}