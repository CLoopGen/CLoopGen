#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

unsigned char *original;
int i;

void init_vars() {
    size_t size = 512 * 1024; // 512 KB to target ~0.01 sec runtime
    original = (unsigned char*)malloc(size);
    if (!original) {
        exit(1);
    }
}