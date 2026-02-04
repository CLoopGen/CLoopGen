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
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024 / sizeof(uint16_t))

static uint16_t n_buffer[TOTAL_ELEMENTS];
static uint16_t o_buffer[TOTAL_ELEMENTS];

void init_vars() {
    const size_t total_elements = TOTAL_ELEMENTS;
    
    w = total_elements - (abs(ns) << 1) - 1;
    if (w <= 0) {
        w = total_elements > 10 ? 10 : 0;
    }

    nptr = n_buffer;
    optr = o_buffer;

    for (size_t i = 0; i < total_elements; i++) {
        n_buffer[i] = rand() & 0xFFFF;
        o_buffer[i] = rand() & 0xFFFF;
    }

    pdif = 0;
    tdif = 0;
    t = 0;
    rend = NULL;
}