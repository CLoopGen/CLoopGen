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
    size_t j;
    for (i = 0; i < adin_len && i < pool->alloc_len; ++i) {
        j = (i * 7) % pool->len;
        pool->buffer[j] ^= adin[i];
        pool->buffer[j] ^= (adin[i] << 1) | (adin[i] >> 7);
    }
}
