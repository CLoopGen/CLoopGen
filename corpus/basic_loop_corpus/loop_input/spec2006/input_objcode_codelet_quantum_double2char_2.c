#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *buf;
int i;
unsigned char *p;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB of data for ~0.01 sec runtime

    buf = (unsigned char *)malloc(data_size);
    p = (unsigned char *)malloc(data_size);

    if (!buf || !p) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    memset(p, 0xAA, data_size); // Initialize with arbitrary pattern
}