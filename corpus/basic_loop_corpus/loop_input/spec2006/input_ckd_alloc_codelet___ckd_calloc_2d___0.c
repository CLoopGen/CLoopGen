#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef int int32;

int32 d1 = 65536;
int32 d2 = 4;
int32 elemsize = 16;
char **ref;
char *mem;
int32 i;
int32 offset;

void init_vars() {
    mem = (char*)aligned_alloc(64, d1 * d2 * elemsize);
    ref = (char**)aligned_alloc(64, d1 * sizeof(char*));

    if (!mem || !ref) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int32 idx = 0; idx < d1; ++idx) {
        ref[idx] = NULL;
    }
}