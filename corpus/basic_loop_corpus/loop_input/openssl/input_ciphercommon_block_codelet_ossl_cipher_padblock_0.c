#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *buf;
size_t *buflen;
size_t blocksize;
size_t i;
unsigned char pad;

void init_vars() {
    blocksize = 512 * 1024; // 512 KB
    buf = aligned_alloc(64, blocksize);
    buflen = malloc(sizeof(size_t));
    *buflen = blocksize / 2; // Start halfway
    pad = 0xFF;
    i = 0;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}