#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *aseq;
int rlen;

static char data[1 << 20]; // 1MB of input data

void init_vars() {
    const size_t len = sizeof(data) - 1;
    for (size_t i = 0; i < len; i++) {
        int c = rand() % 128;
        if (c == 0) c = 'a'; // avoid null byte
        data[i] = (char)c;
    }
    data[len] = '\0'; // null terminate

    aseq = data;
    rlen = 0;
}