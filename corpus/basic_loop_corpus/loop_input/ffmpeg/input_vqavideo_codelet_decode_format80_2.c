#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned char *dest;
int dest_index;
int count;
int src_pos;
int i;

#define DATA_SIZE (128 << 20) // 128 MB

static unsigned char data[DATA_SIZE];

void init_vars() {
    dest = data;
    count = 64 << 20; // 64 million iterations
    src_pos = 0;
    dest_index = (32 << 20); // Ensure src_pos + count and dest_index + count are within bounds
}