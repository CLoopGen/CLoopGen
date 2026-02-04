#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct entry {
    int l;
    int r;
    int val;
    struct entry *pnext;
} entry_t;

typedef struct test_array {
    entry_t *hash[4096];
} test_array_t;

test_array_t *pta;
int h;

void init_vars() {
    pta = (test_array_t *)calloc(1, sizeof(test_array_t));
    if (!pta) {
        exit(1);
    }
}

void loop(); 

__attribute__((constructor))
static void auto_init() {
    init_vars();
}