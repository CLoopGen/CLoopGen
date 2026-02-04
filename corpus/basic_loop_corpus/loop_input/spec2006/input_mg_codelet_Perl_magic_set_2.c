#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef size_t STRLEN;

STRLEN len = 16777216; // 16MB data size for ~0.01 sec runtime on modern CPU
STRLEN i;
int accumulate = 0;
int any_fatals = 0;
char *ptr;

void init_vars() {
    ptr = (char *)malloc(len);
    if (!ptr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (STRLEN j = 0; j < len; ++j) {
        ptr[j] = (char)(j & 255);
    }
}