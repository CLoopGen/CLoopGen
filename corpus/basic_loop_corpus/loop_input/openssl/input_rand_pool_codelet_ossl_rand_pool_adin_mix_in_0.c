#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

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

RAND_POOL *pool;
unsigned char *adin;
size_t adin_len;
size_t i;

void init_vars() {
    const size_t data_size = 512 * 1024; // 512 KB for ~0.01 sec runtime

    pool = (RAND_POOL *)malloc(sizeof(RAND_POOL));
    pool->len = 256 * 1024; // 256 KB buffer length
    pool->buffer = (unsigned char *)malloc(pool->len * sizeof(unsigned char));
    pool->attached = 1;
    pool->secure = 0;
    pool->min_len = 128;
    pool->max_len = 1024 * 1024;
    pool->alloc_len = pool->len;
    pool->entropy = 0;
    pool->entropy_requested = 0;

    adin_len = data_size;
    adin = (unsigned char *)malloc(adin_len * sizeof(unsigned char));

    for (size_t idx = 0; idx < pool->len; ++idx) {
        pool->buffer[idx] = (unsigned char)(idx & 0xFF);
    }
    for (size_t idx = 0; idx < adin_len; ++idx) {
        adin[idx] = (unsigned char)((idx * 31) & 0xFF);
    }

    i = 0;
}