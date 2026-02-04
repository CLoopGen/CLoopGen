#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint64_t *hcode;
uint64_t n[59];
int i;

void init_vars() {
    const int size = 1 << 16;
    hcode = malloc(size * sizeof(uint64_t));
    for (int idx = 0; idx < size; ++idx) {
        hcode[idx] = rand() % 59;
    }
}