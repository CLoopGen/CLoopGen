#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
char *sep;
int i;
int j;

static char *s_buffer;
static char *sep_buffer;

void init_vars() {
    size_t s_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime
    s_buffer = malloc(s_size);
    if (!s_buffer) exit(1);

    sep_buffer = malloc(256);
    if (!sep_buffer) exit(1);

    // Initialize separator characters: use a mix of common delimiters
    const char init_sep[] = " \t\n\r\f\v.,;:!-";
    size_t sep_len = strlen(init_sep);
    memcpy(sep_buffer, init_sep, sep_len + 1);

    // Fill the main string with separators and non-separator chars
    // Start with many separators so that loop runs through them
    size_t pos = 0;
    while (pos < s_size - 256) {
        // Add blocks of separators
        for (int k = 0; k < 16 && pos < s_size - 1; k++) {
            s_buffer[pos++] = init_sep[k % sep_len];
        }
        // Occasionally insert a non-separator to avoid infinite loops
        if (pos < s_size - 1) {
            s_buffer[pos++] = 'A'; // non-separator
        }
    }
    // Ensure null termination
    s_buffer[s_size - 1] = '\0';

    // Assign pointers
    s = s_buffer;
    sep = sep_buffer;

    // Initialize loop indices
    i = 0;
    j = 0;
}