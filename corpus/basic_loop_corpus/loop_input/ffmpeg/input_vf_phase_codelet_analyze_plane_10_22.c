#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w;
int64_t bdif;
int64_t tdif;
int64_t pdif;
int t;
uint16_t *rend;

#define DATA_SIZE (64 * 1024 * 1024)  // ~128MB of total data (two arrays)

static uint16_t *n_array;
static uint16_t *o_array;

void init_vars() {
    n_array = (uint16_t*)aligned_alloc(32, (DATA_SIZE + 4) * sizeof(uint16_t));
    o_array = (uint16_t*)aligned_alloc(32, (DATA_SIZE + 4) * sizeof(uint16_t));

    if (!n_array || !o_array) {
        exit(1);
    }

    for (size_t i = 0; i < DATA_SIZE + 4; i++) {
        n_array[i] = rand() & 0xFFFF;
        o_array[i] = rand() & 0xFFFF;
    }

    nptr = n_array + 2;
    optr = o_array + 2;
    w = DATA_SIZE;

    bdif = 0;
    tdif = 0;
    pdif = 0;
    t = 0;
    rend = NULL;
}