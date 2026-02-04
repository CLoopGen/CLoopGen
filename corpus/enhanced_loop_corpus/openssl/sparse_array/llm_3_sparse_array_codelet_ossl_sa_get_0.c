#include <stdio.h>

#include <inttypes.h>

typedef uintmax_t ossl_uintmax_t;

struct sparse_array_st {
    int levels;
    ossl_uintmax_t top;
    size_t nelem;
    void **nodes;
};


typedef struct sparse_array_st OPENSSL_SA;

extern  OPENSSL_SA *sa;
extern ossl_uintmax_t n;
extern int level;
extern void **p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (Flattened Index) Memory Access Pattern
    // Simulate consecutive access by precomputing all indices and traversing in increasing order
    // using a flattened path stored in a local array, then walking forward through it
    void **path[32];  // Assume max levels <= 32
    ossl_uintmax_t indices[32];
    int max_level = sa->levels - 1;
    int i;

    // Precompute all indices from top to bottom
    for (i = 0; i <= max_level; i++) {
        indices[i] = (n >> (4 * i)) & ((1 << 4) - 1);
    }

    // Traverse levels in increasing order (consecutive memory access simulation)
    p = (void **)sa->nodes;
    for (level = 0; p != ((void *)0) && level < max_level; level++) {
        path[level] = p;
        p = (void **)p[indices[max_level - 1 - level]]; // Reverse order to maintain logic
    }

    // Now walk back up using the saved path (simulate original downward effect with reversed access)
    for (i = max_level - 1; i >= 0; i--) {
        p = path[i];
    }
}
