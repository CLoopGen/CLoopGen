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
    int outer_level;
    for (outer_level = sa->levels - 1; p != ((void *)0) && outer_level > 1; outer_level--) {
        level = outer_level;
        p = (void **)p[(n >> (4 * level)) & ((1 << 4) - 1)];
        if (p == ((void *)0)) break;
        level = outer_level - 1;
        p = (void **)p[(n >> (4 * level)) & ((1 << 4) - 1)];
    }
}
