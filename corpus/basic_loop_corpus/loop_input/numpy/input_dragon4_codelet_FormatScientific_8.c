#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *pCurOut;
char *pEnd;

static char *buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    buffer = (char *)calloc(data_size, sizeof(char));
    if (!buffer) {
        exit(1);
    }

    pCurOut = buffer;
    pEnd = buffer + data_size;
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}