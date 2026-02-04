#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 65536; // ~256KB of data (65536 * 2 * 2 = 262144 bytes)
int64_t bdif = 0;
int64_t tdif = 0;
int t = 0;
uint16_t *rend;

static uint16_t *narr;
static uint16_t *oarr;

void init_vars() {
    size_t total_size = w + 4; // Add padding for safe indexing with offsets

    narr = calloc(total_size, sizeof(uint16_t));
    oarr = calloc(total_size, sizeof(uint16_t));

    if (!narr || !oarr) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        narr[i] = rand() & 0xFFFF;
        oarr[i] = rand() & 0xFFFF;
    }

    nptr = narr + 2;  // Base pointer offset to allow negative indexing
    optr = oarr + 2;
}