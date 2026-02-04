#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *in1;
unsigned char *in2;
size_t len;
unsigned char *out;
size_t i;

void init_vars() {
    len = 512 * 1024; // 512 KB data size for ~0.01 sec runtime on modern CPU

    in1 = (unsigned char *)malloc(len);
    in2 = (unsigned char *)malloc(len);
    out = (unsigned char *)malloc(len);

    if (!in1 || !in2 || !out) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t j = 0; j < len; j++) {
        in1[j] = (unsigned char)(j & 0xFF);
        in2[j] = (unsigned char)((j + 32) & 0xFF);
    }
}