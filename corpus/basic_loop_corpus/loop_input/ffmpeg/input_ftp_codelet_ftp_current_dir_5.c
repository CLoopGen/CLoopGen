#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *res;
char *start;
char *end;
int i;

static char *buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    buffer = (char *)malloc(data_size);
    if (!buffer) exit(1);

    memset(buffer, 'a', data_size - 1);
    buffer[0] = '"';
    buffer[data_size - 1] = '\0'; 

    res = buffer;
    start = NULL;
    end = NULL;
    i = 0;
}