#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;

JSAMPLE invalue = 42;
int h_expand = 1 << 20;  // 1 million iterations for ~0.01 sec on modern CPU
int h;

JSAMPLE *outptr_base;
JSAMPROW outptr;

void init_vars() {
    size_t data_size = (size_t)h_expand * sizeof(JSAMPLE);
    outptr_base = (JSAMPLE *)calloc(data_size, 1);
    if (!outptr_base) {
        exit(1);
    }
    outptr = outptr_base;
}