#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns;
int os;
uint8_t *nptr;
uint8_t *optr;
int w;
int bdif;
int tdif;
int pdif;
int t;
uint8_t *rend;

#define DATA_SIZE (16 << 20)  // 16 MB for ~0.01 sec runtime

static uint8_t *nptr_data;
static uint8_t *optr_data;

void init_vars() {
    // Initialize scalar variables
    ns = 1;
    os = 1;
    w = DATA_SIZE - 2;  // Ensure access up to [ns<<1] and [-(ns)] is valid
    bdif = 0;
    tdif = 0;
    pdif = 0;
    t = 0;

    // Allocate buffers with padding to prevent out-of-bounds access
    nptr_data = (uint8_t*)calloc(DATA_SIZE + 4, sizeof(uint8_t));
    optr_data = (uint8_t*)calloc(DATA_SIZE + 4, sizeof(uint8_t));

    if (!nptr_data || !optr_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize data with non-zero values for meaningful computation
    for (int i = 0; i < DATA_SIZE + 4; i++) {
        nptr_data[i] = rand() & 0xFF;
        optr_data[i] = rand() & 0xFF;
    }

    // Set nptr and optr to point to base of usable data (with one element padding on left/right)
    nptr = nptr_data + 1;
    optr = optr_data + 1;

    // Ensure loop bounds are safe: nptr < rend where rend = nptr + w
    // Accesses: nptr[ns], nptr[ns<<1], nptr[-ns] => need at least (ns<<1) padding on both ends
    // Since ns = 1, we have sufficient padding via +1 offset
}