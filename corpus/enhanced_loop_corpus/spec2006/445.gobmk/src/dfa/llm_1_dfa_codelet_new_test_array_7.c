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
    for (int i = 0; i != 2048; i++) {
        pta->hash[i] = ((void *)0);
        pta->hash[i + 2048] = ((void *)0);
    }
}
