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
    int stride = 1;
    for (h = 0; h != 4096; h += stride) {
        pta->hash[h] = ((void *)0);
        stride = (h % 256 == 0) ? 3 : 1; // Occasionally skip more indices, varying effective trip count and access pattern
    }
}
