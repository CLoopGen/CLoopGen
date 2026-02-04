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
    size_t stride = 2;
    size_t buffer_len = pool->len;
    for (i = 0; i < adin_len; i += stride)
        pool->buffer[(i % buffer_len)] ^= adin[i];
    if (adin_len > 0 && stride > 1) {
        for (i = 1; i < adin_len; i += stride)
            pool->buffer[(i % buffer_len)] ^= adin[i];
    }
}
