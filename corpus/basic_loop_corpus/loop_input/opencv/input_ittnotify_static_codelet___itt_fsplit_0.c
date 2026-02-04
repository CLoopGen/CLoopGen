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
    size_t s_len = 128 << 20; // 128 MB
    size_t sep_len = 64;

    s_buffer = (char*)calloc(s_len + 1, sizeof(char));
    sep_buffer = (char*)calloc(sep_len + 1, sizeof(char));

    if (!s_buffer || !sep_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < sep_len; idx++) {
        sep_buffer[idx] = (char)('A' + (idx % 26));
    }
    sep_buffer[sep_len] = '\0';

    for (size_t idx = 0; idx < s_len; idx++) {
        s_buffer[idx] = sep_buffer[idx % sep_len];
    }
    s_buffer[s_len] = 'x'; // Ensure a character not in sep appears at the end

    s = s_buffer;
    sep = sep_buffer;
    i = 0;
    j = 0;
}