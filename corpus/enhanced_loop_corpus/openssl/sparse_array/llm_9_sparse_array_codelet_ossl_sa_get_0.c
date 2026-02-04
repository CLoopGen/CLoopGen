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
    int unroll_factor = 2;
    int start_level = sa->levels - 1;
    for (level = start_level; p != ((void *)0) && level > 1; level -= unroll_factor) {
        void **next1 = (void **)p[(n >> (4 * level)) & 15];
        void **next2 = (void **)(next1 ? next1[(n >> (4 * (level - 1))) & 15] : NULL);
        p = next2;
        if (!p) break;
    }
    if (p != ((void *)0) && level == 1) {
        p = (void **)p[(n >> 4) & 15];
    }
}
