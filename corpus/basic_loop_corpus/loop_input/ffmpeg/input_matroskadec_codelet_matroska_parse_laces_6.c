#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int size;
uint32_t lace_size[256];
int *laces;
int n;

void init_vars() {
    size = 134217728; // 128MB to target ~0.01s runtime
    laces = (int*)malloc(sizeof(int));
    *laces = 256;
}

void loop();