#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *block;
unsigned int blocksize;
unsigned int carry;
int b;

void init_vars() {
    blocksize = 512 * 1024; // 512KB data size for ~0.01 sec runtime
    block = (unsigned char *)malloc(blocksize);
    if (!block) {
        exit(1);
    }
    memset(block, 0xFF, blocksize); // Initialize with non-zero values
    carry = 256; // Ensure carry is non-zero to enter loop
    b = 0;
}