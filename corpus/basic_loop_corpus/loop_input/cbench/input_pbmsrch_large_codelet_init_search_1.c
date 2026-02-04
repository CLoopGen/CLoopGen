#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

size_t table[256];
size_t len;
char *string;
size_t i;

void init_vars() {
    len = 100000000; // ~100 million iterations for ~0.01 sec on modern CPU
    string = (char *)malloc(len);
    if (!string) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (size_t idx = 0; idx < len; idx++) {
        string[idx] = (char)(idx % 256);
    }
    for (int idx = 0; idx < 256; idx++) {
        table[idx] = 0;
    }
    i = 0;
}