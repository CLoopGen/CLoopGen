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
    internal_len = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPUs
    internal_s = (char *)malloc(internal_len);
    if (!internal_s) {
        internal_len = 0;
        s = NULL;
        len = 0;
        return;
    }

    memset(internal_s, 'x', internal_len - 1); // Fill with non-zero
    internal_s[internal_len - 1] = '\0';       // Null terminate at end

    s = internal_s;
    len = internal_len;
}