#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern unsigned char *out;
extern size_t olen;
extern size_t i;
extern unsigned char *tmp;

unsigned char *out;
size_t olen;
size_t i;
unsigned char *tmp;

void init_vars() {
    olen = 512 * 1024; // 512 KB data size for ~0.01 sec runtime on modern CPU
    out = (unsigned char *)malloc(olen);
    tmp = (unsigned char *)malloc(olen);

    if (!out || !tmp) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize arrays to non-zero values to make XOR observable
    for (size_t j = 0; j < olen; j++) {
        out[j] = (unsigned char)(j & 0xFF);
        tmp[j] = (unsigned char)((j + 1) & 0xFF);
    }
}