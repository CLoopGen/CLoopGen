#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int int32;

int32 d1 = 512;
int32 d2 = 512;
int32 d3 = 1;
int32 elemsize = 4;
char ***ref1;
char *mem;
int32 i;
int32 j;
int32 offset = 0;

void init_vars() {
    mem = (char*)aligned_alloc(32, d1 * d2 * d3 * elemsize);
    if (!mem) exit(1);

    ref1 = (char***)calloc(d1, sizeof(char**));
    if (!ref1) exit(1);

    for (i = 0; i < d1; i++) {
        ref1[i] = (char**)calloc(d2, sizeof(char*));
        if (!ref1[i]) exit(1);
    }

    memset(mem, 0, d1 * d2 * d3 * elemsize);
}