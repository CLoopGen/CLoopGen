#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

#define DATA_SIZE (1 << 20) // 1MB data size for ~0.01 sec runtime

char buffer[4];
int i;
char *vPtr;

void init_vars() {
    static char internal_buffer[DATA_SIZE];
    vPtr = internal_buffer;
    memset(buffer, 0x55, sizeof(buffer)); // Initialize buffer with sample data
}