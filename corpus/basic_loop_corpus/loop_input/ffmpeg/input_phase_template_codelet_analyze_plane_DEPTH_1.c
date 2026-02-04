#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w;
int64_t tdif;
int64_t pdif;
int t;
uint16_t *rend;

static uint16_t *n_array;
static uint16_t *o_array;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of data for each array
    size_t num_elements = data_size / sizeof(uint16_t);

    n_array = aligned_alloc(32, (num_elements + 4) * sizeof(uint16_t));
    o_array = aligned_alloc(32, (num_elements + 4) * sizeof(uint16_t));

    for (size_t i = 0; i < num_elements + 4; i++) {
        n_array[i] = rand() % 100;
        o_array[i] = rand() % 100;
    }

    nptr = n_array + 2;
    optr = o_array + 2;
    w = num_elements - 4;

    tdif = 0;
    pdif = 0;
    t = 0;
    rend = NULL;
}