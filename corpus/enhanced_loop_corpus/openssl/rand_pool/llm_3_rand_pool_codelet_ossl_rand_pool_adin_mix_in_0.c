#include <stdio.h>

#include <inttypes.h>

typedef struct rand_pool_st {
    unsigned char *buffer;
    size_t len;
    int attached;
    int secure;
    size_t min_len;
    size_t max_len;
    size_t alloc_len;
    size_t entropy;
    size_t entropy_requested;
} RAND_POOL;

extern RAND_POOL *pool;
extern  unsigned char *adin;
extern size_t adin_len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)adin; // reinterpret adin as array of indices (unsafe in practice but valid for mutation exploration)
    size_t num_indices = adin_len / sizeof(size_t);
    size_t buffer_len = pool->len;
    for (i = 0; i < num_indices; ++i) {
        size_t idx = indices[i] % buffer_len;
        size_t src_idx = i * sizeof(size_t) % adin_len;
        pool->buffer[idx] ^= adin[src_idx];
    }
}
