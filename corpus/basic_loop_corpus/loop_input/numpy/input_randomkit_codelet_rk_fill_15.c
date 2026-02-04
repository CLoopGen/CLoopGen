#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size = 16777216; // 16MB data size for ~0.01 sec runtime
unsigned long r = 0xDEADBEEFCAFEBABEUL;
unsigned char *buf;

void init_vars() {
    buf = (unsigned char *)aligned_alloc(32, size);
    if (!buf) {
        exit(1);
    }
}