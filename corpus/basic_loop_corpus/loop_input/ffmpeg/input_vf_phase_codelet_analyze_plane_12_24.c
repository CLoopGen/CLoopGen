#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w;
int64_t tdif;
int64_t pdif;
int t;
uint16_t *rend;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / sizeof(uint16_t))

static uint16_t n_array[TOTAL_ELEMENTS];
static uint16_t o_array[TOTAL_ELEMENTS];

void init_vars() {
    size_t i;

    w = TOTAL_ELEMENTS - (abs(ns) << 1) - 1;
    if (w <= 0) {
        w = TOTAL_ELEMENTS / 2;
        ns = 1;
        os = 1;
    }

    nptr = n_array + (abs(ns) << 1);
    optr = o_array + (abs(os) << 1);

    for (i = 0; i < TOTAL_ELEMENTS; i++) {
        n_array[i] = rand() & 0xFFFF;
        o_array[i] = rand() & 0xFFFF;
    }

    pdif = 0;
    tdif = 0;
    t = 0;
    rend = nptr + w;
}