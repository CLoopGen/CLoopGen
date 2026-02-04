#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *buffer;
int bit_size;
int i;

void init_vars() {
    bit_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec on modern CPU
    buffer = (char *)calloc(bit_size, sizeof(char));
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    i = 0;
}