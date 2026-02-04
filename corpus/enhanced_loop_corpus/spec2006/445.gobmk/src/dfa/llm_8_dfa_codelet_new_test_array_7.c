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
    for (h = 0; h < 4096; h += 4) {
        pta->hash[h] = ((void *)0);
        pta->hash[h + 1] = ((void *)0);
        pta->hash[h + 2] = ((void *)0);
        pta->hash[h + 3] = ((void *)0);
    }
}
