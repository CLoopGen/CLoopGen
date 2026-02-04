#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int wchar_bytes;
char *q;
int i;

char *q_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64 MB to target ~0.01 sec on modern CPU
    q_buffer = (char *)calloc(data_size, sizeof(char));
    if (!q_buffer) {
        exit(1);
    }
    wchar_bytes = data_size;
    q = q_buffer;
    i = 0;
}