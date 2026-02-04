#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

static char *internal_s;
static size_t internal_len = 131072; // ~128KB data size for ~0.01 sec runtime

void init_vars() {
    internal_s = (char*)malloc(internal_len);
    if (!internal_s) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize most bytes to non-zero
    for (size_t j = 0; j < internal_len - 1; ++j) {
        internal_s[j] = 'a';
    }
    // Place null terminator near the end to ensure loop runs long but terminates
    internal_s[internal_len - 1] = '\0';

    s = internal_s;
    len = internal_len;
    i = 0;
}

// Forward declaration of loop function from other translation unit
void loop(void);