#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

unsigned char *buffer;
int wd_size;
int i;

void init_vars() {
    wd_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPUs
    buffer = (unsigned char *)calloc(wd_size, sizeof(unsigned char));
    if (!buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    i = 0;
}