#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef uintmax_t ossl_uintmax_t;

struct sparse_array_st {
    int levels;
    ossl_uintmax_t top;
    size_t nelem;
    void **nodes;
};

typedef struct sparse_array_st OPENSSL_SA;

static OPENSSL_SA sa_instance;
OPENSSL_SA *sa = &sa_instance;

static void **node_level2 = NULL;
static void **node_level1 = NULL;
static void **node_level0 = NULL;

void **p = NULL;

ossl_uintmax_t n = 0x123456789ABCDEF0ULL;

int level;

void init_vars() {
    sa->levels = 3;
    sa->top = 0;
    sa->nelem = 16;
    
    node_level2 = calloc(16, sizeof(void*));
    node_level1 = calloc(16, sizeof(void*));
    node_level0 = calloc(16, sizeof(void*));

    for (int i = 0; i < 16; i++) {
        if (i % 3 == 0) node_level2[i] = node_level1;
        if (i % 5 == 0) node_level1[i] = node_level0;
    }

    sa->nodes = node_level2;
    p = sa->nodes;
    n = 0x123456789ABCDEF0ULL;
}

__attribute__((destructor))
static void cleanup() {
    free(node_level0);
    free(node_level1);
    free(node_level2);
}