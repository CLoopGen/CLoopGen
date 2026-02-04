#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t p;

void init_vars() {
    size1 = 64 * 1024 * 1024; // 64 million iterations for ~0.01 sec on modern CPU
}