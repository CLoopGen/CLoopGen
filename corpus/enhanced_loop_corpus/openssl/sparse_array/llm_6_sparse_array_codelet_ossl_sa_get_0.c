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
    ossl_uintmax_t index;
    for (level = sa->levels - 1; p != ((void *)0) && level > 0; level--) {
        index = (n >> (4 * level)) & ((1 << 4) - 1);
        p = (void **)p[index];
    }
}
