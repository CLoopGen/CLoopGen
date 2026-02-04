#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int id = 42;

size_t i;
size_t v = 1024 * 512; // 512 KB data size for ~0.01 sec runtime

unsigned char *D;

void init_vars() {
    D = (unsigned char *)aligned_alloc(64, v * sizeof(unsigned char));
    if (!D) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    memset(D, 0, v * sizeof(unsigned char));
}