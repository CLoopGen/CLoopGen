#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct AVFilterFormats {
    unsigned int nb_formats;
    int *formats;
    unsigned int refcount;
    struct AVFilterFormats ***refs;
};

typedef struct AVFilterFormats AVFilterFormats;

// Define external variables
AVFilterFormats *b;
AVFilterFormats *ret;
int i;

// Helper function to allocate and initialize a 3-star pointer structure
static AVFilterFormats ***alloc_refs_array(unsigned int count) {
    AVFilterFormats ***refs = malloc(count * sizeof(AVFilterFormats**));
    for (unsigned int i = 0; i < count; i++) {
        refs[i] = malloc(sizeof(AVFilterFormats*));
    }
    return refs;
}

void init_vars() {
    // Allocate b and ret
    b = malloc(sizeof(AVFilterFormats));
    ret = malloc(sizeof(AVFilterFormats));

    // Set refcount values
    // Aim for ~0.01s runtime: this loop does pointer assignments and dereferences
    // Each iteration is very fast, so we need a moderate number of iterations
    // Modern CPU can do billions of ops/sec, so 1M iterations ~ 1ms, 10M ~ 10ms
    b->refcount = 8000000; // ~8M iterations for ~0.01s target

    // Initialize b's refs array
    b->refs = alloc_refs_array(b->refcount);
    for (unsigned int i = 0; i < b->refcount; i++) {
        b->refs[i][0] = malloc(sizeof(AVFilterFormats));
        b->refs[i][0]->refs = NULL;
        b->refs[i][0]->refcount = 0;
    }

    // Initialize ret
    ret->refcount = 0;
    // Pre-allocate ret->refs to avoid out-of-bounds access
    // Maximum possible size needed: ret->refcount will grow up to b->refcount
    ret->refs = alloc_refs_array(b->refcount);
}