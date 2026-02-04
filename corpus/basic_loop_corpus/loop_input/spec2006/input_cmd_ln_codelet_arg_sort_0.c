#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef int int32;

int32 n = 1 << 24; // 16 million elements, roughly 64 MB for the array
int32 *pos = NULL;
int32 i = 0;

void init_vars() {
    pos = (int32*)calloc(n, sizeof(int32));
    if (!pos) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}