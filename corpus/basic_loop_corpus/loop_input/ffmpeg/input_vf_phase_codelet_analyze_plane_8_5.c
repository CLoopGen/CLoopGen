#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint8_t *nptr;
uint8_t *optr;
int w = 64 * 1024 * 1024; // 64 million iterations for ~0.01 sec runtime
int bdif = 0;
int tdif = 0;
int t = 0;
uint8_t *rend;

static uint8_t *nbuf;
static uint8_t *obuf;

void init_vars() {
    size_t total_size = (size_t)w + 4; // Add padding to prevent out-of-bounds access

    nbuf = (uint8_t*)calloc(total_size, sizeof(uint8_t));
    obuf = (uint8_t*)calloc(total_size, sizeof(uint8_t));

    if (!nbuf || !obuf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    nptr = nbuf + 2; // Start nptr at offset 2 to allow indexing [-ns] and [ns<<1]
    optr = obuf + 2; // Same for optr

    // Initialize buffer contents to small non-zero values to avoid trivial differences
    for (size_t i = 0; i < total_size - 4; i++) {
        nbuf[i] = (uint8_t)((i + 13) & 0xFF);
        obuf[i] = (uint8_t)((i + 37) & 0xFF);
    }
}