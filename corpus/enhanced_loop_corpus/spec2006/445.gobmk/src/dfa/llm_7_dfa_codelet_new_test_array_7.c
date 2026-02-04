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
    volatile int prev = 0;
    for (h = 0; h != 4096; h++) {
        pta->hash[h] = (entry_t*)((uintptr_t)prev & ~((uintptr_t)7));
        prev = h + 1;
    }
}
