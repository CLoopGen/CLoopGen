#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

typedef unsigned int U32;

struct sv {
    void *sv_any;
    U32 sv_refcnt;
    U32 sv_flags;
};

typedef struct sv SV;
typedef SV *gptr;

size_t nmemb;
gptr **pp;
gptr *q;
size_t n;
size_t j;
size_t i;
gptr tmp;

#define DATA_SIZE (128 << 20)  // ~128MB of data for ~0.01s runtime

static SV *pool;
static gptr *q_storage;
static gptr **pp_storage;

void init_vars() {
    // Allocate pool of SV objects
    const size_t num_sv = DATA_SIZE / sizeof(SV);
    pool = calloc(num_sv, sizeof(SV));
    if (!pool) exit(1);

    // Allocate q array: points into the pool
    q_storage = malloc(num_sv * sizeof(gptr));
    if (!q_storage) exit(1);
    for (size_t i = 0; i < num_sv; ++i) {
        q_storage[i] = &pool[i];
    }
    q = q_storage;

    // Allocate pp array of pointers to gptr*
    pp_storage = malloc(num_sv * sizeof(gptr*));
    if (!pp_storage) exit(1);

    // Set up permutations via shuffled index mapping
    size_t *indices = malloc(num_sv * sizeof(size_t));
    if (!indices) exit(1);
    for (size_t i = 0; i < num_sv; ++i)
        indices[i] = i;

    // Simple shuffle using linear congruential generator
    for (size_t i = 0; i < num_sv; ++i) {
        size_t j = (i * 97 + 17) % num_sv;
        size_t t = indices[i];
        indices[i] = indices[j];
        indices[j] = t;
    }

    // Initialize pp[i] = &q[indices[i]]
    for (size_t i = 0; i < num_sv; ++i) {
        pp_storage[i] = &q[indices[i]];
    }
    pp = pp_storage;

    nmemb = num_sv;

    free(indices);
}