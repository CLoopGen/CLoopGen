#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef char Char;
typedef int Int32;

Char tmpName[1034];
Int32 j;
Int32 k = 1034;
Char *p;

void init_vars() {
    p = (Char *)malloc(k * sizeof(Char));
    if (!p) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (Int32 i = 0; i < k; i++) {
        p[i] = (Char)(i % 128);
    }
}