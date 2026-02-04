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

static char *create_buffer(size_t size) {
    char *buf = (char *)malloc(size);
    if (!buf) exit(1);
    return buf;
}

void init_vars() {
    const size_t s_len = 64 * 1024 * 1024; // 64 MB
    const size_t sep_len = 32;

    s = create_buffer(s_len);
    sep = create_buffer(sep_len);

    for (size_t idx = 0; idx < sep_len - 1; idx++) {
        sep[idx] = 'a' + (idx % 26);
    }
    sep[sep_len - 1] = '\0';

    size_t prefix_len = sep_len * 4;
    for (size_t idx = 0; idx < prefix_len; idx++) {
        s[idx] = sep[idx % (sep_len - 1)];
    }
    for (size_t idx = prefix_len; idx < s_len - 1; idx++) {
        s[idx] = 'X'; 
    }
    s[s_len - 1] = '\0';

    i = 0;
    j = 0;
}