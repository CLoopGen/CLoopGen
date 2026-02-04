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
    for (int i = 0; i != 64; i++) {
        for (int j = 0; j != 64; j++) {
            pta->hash[i * 64 + j] = ((void *)0);
        }
    }
}
