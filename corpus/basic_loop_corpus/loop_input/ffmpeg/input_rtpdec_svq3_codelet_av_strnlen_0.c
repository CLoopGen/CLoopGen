#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

static char *internal_s;
static size_t internal_len = 1 << 24; // ~16.7 million chars, approx 16MB

void init_vars() {
    if (internal_s) return; // Prevent re-initialization
    internal_s = malloc(internal_len);
    if (!internal_s) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    memset(internal_s, 'x', internal_len - 1); // Fill with non-zero
    internal_s[internal_len - 1] = '\0'; // Null terminate at end

    s = internal_s;
    len = internal_len;
    i = 0;
}