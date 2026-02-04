#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
char *sep;
int i;
int j;

static char s_buffer[1048576];  // 1MB buffer for s
static char sep_buffer[256];   // 256-byte buffer for sep

void init_vars() {
    size_t s_len = sizeof(s_buffer) - 1;
    size_t sep_len = 128;

    for (size_t idx = 0; idx < s_len; idx++) {
        s_buffer[idx] = 'a' + (idx % 26);
    }
    s_buffer[s_len] = '\0';

    for (size_t idx = 0; idx < sep_len; idx++) {
        sep_buffer[idx] = 'a' + (idx % 26);
    }
    sep_buffer[sep_len] = '\0';

    s = s_buffer;
    sep = sep_buffer;
    i = 0;
    j = 0;
}