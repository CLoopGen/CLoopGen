#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *pattern;
int patternLen;
int backslashCount;

void init_vars() {
    patternLen = 1 << 20; // Approximately 1MB of data
    pattern = (char *)malloc(patternLen);
    if (!pattern) {
        patternLen = 0;
        backslashCount = 0;
        return;
    }

    memset(pattern, 'a', patternLen);
    int num_backslashes = 1000;
    for (int i = patternLen - 2; i >= patternLen - num_backslashes && i >= 0; i--) {
        pattern[i] = '\\';
    }

    backslashCount = 0;
}