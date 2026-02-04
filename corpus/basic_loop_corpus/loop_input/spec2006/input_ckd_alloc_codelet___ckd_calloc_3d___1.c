#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef int int32;

int32 d1 = 65536;
int32 d2 = 4;
char ***ref1;
char **ref2;
int32 i;
int32 offset;

void init_vars() {
    ref2 = (char**)calloc(d1 * d2, sizeof(char*));
    if (!ref2) {
        fprintf(stderr, "Failed to allocate ref2\n");
        exit(1);
    }

    ref1 = (char***)calloc(d1, sizeof(char**));
    if (!ref1) {
        fprintf(stderr, "Failed to allocate ref1\n");
        exit(1);
    }
}