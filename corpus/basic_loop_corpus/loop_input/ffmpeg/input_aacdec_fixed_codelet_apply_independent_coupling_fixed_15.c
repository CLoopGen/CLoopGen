#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int c = 12345;
int shift = 5;
int tmp;
int len = 16777216; // 16M elements to target ~0.01 sec runtime

int *src;
unsigned int *dest;

void init_vars() {
    src = (int*)aligned_alloc(32, len * sizeof(int));
    dest = (unsigned int*)aligned_alloc(32, len * sizeof(unsigned int));

    for (int idx = 0; idx < len; idx++) {
        src[idx] = rand() % 10000;
        dest[idx] = rand() % 10000;
    }
}