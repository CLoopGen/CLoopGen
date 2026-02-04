#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 1024 * 512; // ~1MB of data (1M uint16_t elements)
int64_t bdif;
int64_t pdif;
int t;
uint16_t *rend;

static uint16_t *nptr_base;
static uint16_t *optr_base;
static size_t total_size_n = 0;
static size_t total_size_o = 0;

void init_vars() {
    const size_t element_count = w + (ns << 1) + 1; // Ensure enough space for nptr[ns], nptr[ns<<1], nptr[-ns]
    total_size_n = element_count * sizeof(uint16_t);
    nptr_base = aligned_alloc(64, total_size_n);
    if (!nptr_base) exit(1);

    const size_t o_element_count = w + (os << 1) + 1;
    total_size_o = o_element_count * sizeof(uint16_t);
    optr_base = aligned_alloc(64, total_size_o);
    if (!optr_base) exit(1);

    // Initialize arrays with non-zero values to avoid trivial optimizations
    for (size_t i = 0; i < element_count; i++) {
        nptr_base[i] = (uint16_t)(i & 0xFF);
    }
    for (size_t i = 0; i < o_element_count; i++) {
        optr_base[i] = (uint16_t)((i >> 4) & 0xFF);
    }

    // Set initial pointers so that indexing stays in bounds
    nptr = nptr_base + ns;  // Leave room for negative index access
    optr = optr_base + os;
    rend = NULL;
    bdif = 0;
    pdif = 0;
    t = 0;
}