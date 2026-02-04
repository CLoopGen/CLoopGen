#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB for ~0.01 sec on modern CPU

short *loc;
int words;
int i;
short thisval;
char *dst;
char *src;

static short *loc_buffer;
static char *src_buffer;

void init_vars() {
    loc_buffer = aligned_alloc(64, DATA_SIZE);
    src_buffer = aligned_alloc(64, 2);

    if (!loc_buffer || !src_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (size_t j = 0; j < DATA_SIZE / sizeof(short); j++) {
        loc_buffer[j] = (short)(j & 0xFFFF);
    }

    src_buffer[0] = 0xAB;
    src_buffer[1] = 0xCD;

    loc = loc_buffer;
    src = src_buffer;
    words = DATA_SIZE / sizeof(short);
    dst = NULL;
}