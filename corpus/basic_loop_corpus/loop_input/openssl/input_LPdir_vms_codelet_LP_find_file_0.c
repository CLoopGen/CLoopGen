#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *p;
char *r;
size_t l;

static char data[1024 * 512]; // 512 KB of input data

void init_vars() {
    const char pattern[] = "abc^def:ghi>jkl]mno;pqr";
    size_t pattern_len = sizeof(pattern) - 1;
    size_t total_len = sizeof(data);
    size_t pos = 0;

    while (pos <= total_len - pattern_len) {
        memcpy(&data[pos], pattern, pattern_len);
        pos += pattern_len;
    }
    // Ensure null termination
    if (pos < total_len) {
        data[pos] = '\0';
    } else {
        data[total_len - 1] = '\0';
    }

    p = data;
    r = data;
    l = 0;
}