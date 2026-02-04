#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 1048576; // ~2MB of data (1M elements * 2 bytes each)
int64_t tdif;
int64_t pdif;
int t;
uint16_t *rend;

static uint16_t *narr;
static uint16_t *oarr;

void init_vars() {
    size_t total_size = w + (ns << 1);
    narr = calloc(total_size, sizeof(uint16_t));
    oarr = calloc(total_size, sizeof(uint16_t));
    if (!narr || !oarr) {
        exit(1);
    }

    nptr = narr;
    optr = oarr;
}