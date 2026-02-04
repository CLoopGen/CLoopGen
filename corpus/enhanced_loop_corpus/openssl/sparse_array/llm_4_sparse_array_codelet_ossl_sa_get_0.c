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
    for (level = sa->levels - 1; p != ((void *)0) && level >= 0; level--) {
        if (((n >> (4 * level)) & ((1 << 4) - 1)) == 0)
            continue;
        p = (void **)p[(n >> (4 * level)) & ((1 << 4) - 1)];
    }
}
