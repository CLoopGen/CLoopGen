#include <stdio.h>

#include <inttypes.h>

typedef struct entry {
    int l;
    int r;
    int val;
    struct entry *pnext;
} entry_t;

typedef struct test_array {
    entry_t *hash[4096];
} test_array_t;

extern test_array_t *pta;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    entry_t **hash_base = &(pta->hash[0]);
    for (int h1 = 0; h1 != 1024; h1++) {
        hash_base[h1 * 4 + 0] = NULL;
        hash_base[h1 * 4 + 1] = NULL;
        hash_base[h1 * 4 + 2] = NULL;
        hash_base[h1 * 4 + 3] = NULL;
    }
}
