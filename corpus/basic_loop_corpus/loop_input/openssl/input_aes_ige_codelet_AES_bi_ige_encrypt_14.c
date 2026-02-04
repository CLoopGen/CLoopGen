#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

size_t n;
unsigned char tmp[16];
unsigned char *iv2;

void init_vars() {
    // Allocate and initialize iv2 with 16 bytes
    iv2 = (unsigned char *)malloc(16);
    if (!iv2) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (size_t i = 0; i < 16; ++i) {
        tmp[i] = (unsigned char)(i & 0xFF);
        iv2[i] = (unsigned char)((i + 8) & 0xFF);
    }
}