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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing one level at a time in descending order, access every other level (stride of 2)
    // This changes the traversal pattern through the hierarchy, skipping intermediate levels.
    int start_level = sa->levels - 1;
    for (level = (start_level % 2 == 0) ? start_level - 1 : start_level; 
         p != ((void *)0) && level > 0; 
         level -= 2) {
        ossl_uintmax_t index = (n >> (4 * level)) & ((1 << 4) - 1);
        void **next_p = (void **)p[index];
        // If next level is also valid, skip it and go to its child directly if available
        if (level > 1 && next_p != ((void *)0)) {
            ossl_uintmax_t next_index = (n >> (4 * (level - 1))) & ((1 << 4) - 1);
            p = (void **)next_p[next_index];
            level--; // Compensate for double step
        } else {
            p = next_p;
        }
    }
}
