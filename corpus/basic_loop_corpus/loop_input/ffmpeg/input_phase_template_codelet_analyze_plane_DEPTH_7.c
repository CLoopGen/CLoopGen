#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 1024 * 512; // 1MB of data (each uint16_t is 2 bytes)
int64_t bdif = 0;
int64_t tdif = 0;
int64_t pdif = 0;
int t = 0;
uint16_t *rend;

static uint16_t *n_array;
static uint16_t *o_array;

void init_vars() {
    const size_t array_size = w + (ns << 1) + 1; // Ensure room for ns offsets: -ns, 0, ns, 2*ns
    n_array = aligned_alloc(32, array_size * sizeof(uint16_t));
    o_array = aligned_alloc(32, array_size * sizeof(uint16_t));

    if (!n_array || !o_array) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < array_size; i++) {
        n_array[i] = rand() % 256;
        o_array[i] = rand() % 256;
    }

    nptr = n_array;
    optr = o_array;
}