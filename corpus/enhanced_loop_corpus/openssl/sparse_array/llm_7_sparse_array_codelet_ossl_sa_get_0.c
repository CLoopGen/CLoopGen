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
    int temp_level;
    for (temp_level = sa->levels - 1; p != ((void *)0) && temp_level > 0; temp_level--) {
        void **current_p = p;
        ossl_uintmax_t offset = (n >> (4 * temp_level)) & 15;
        p = (void **)current_p[offset];
    }
}
