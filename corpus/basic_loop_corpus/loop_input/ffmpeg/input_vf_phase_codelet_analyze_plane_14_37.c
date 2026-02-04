#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 65536;
int64_t bdif = 0;
int64_t tdif = 0;
int t = 0;
uint16_t *rend;

uint16_t *n_array;
uint16_t *o_array;

void init_vars() {
    const size_t data_size = 131072; // ~256KB of data (each element is 2 bytes)
    n_array = aligned_alloc(32, data_size * sizeof(uint16_t));
    o_array = aligned_alloc(32, data_size * sizeof(uint16_t));

    for (size_t i = 0; i < data_size; i++) {
        n_array[i] = rand() % 1000;
        o_array[i] = rand() % 1000;
    }

    nptr = n_array;
    optr = o_array;
}