#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

unsigned long *r;
unsigned long *a;
int dl;

static unsigned long *r_buf;
static unsigned long *a_buf;
static size_t total_size = 1024 * 256; // ~2MB total, ensures loop runs sufficiently long

void init_vars() {
    r_buf = aligned_alloc(32, total_size * sizeof(unsigned long));
    a_buf = aligned_alloc(32, total_size * sizeof(unsigned long));

    if (!r_buf || !a_buf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        a_buf[i] = i * 31 + 7; // arbitrary initialization
    }

    r = r_buf;
    a = a_buf;
    dl = total_size;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}