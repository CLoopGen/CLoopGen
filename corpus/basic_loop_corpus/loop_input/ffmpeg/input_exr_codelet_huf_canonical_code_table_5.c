#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint64_t *hcode;
uint64_t n[59];
int i;

void init_vars() {
    const int hcode_size = (1 << 16) + 1; // Size based on loop bound
    hcode = (uint64_t*)aligned_alloc(64, hcode_size * sizeof(uint64_t));
    if (!hcode) {
        exit(1);
    }

    memset(hcode, 0, hcode_size * sizeof(uint64_t));
    memset(n, 0, sizeof(n));

    for (int idx = 0; idx < hcode_size; ++idx) {
        int val = rand() % 60;
        hcode[idx] = val;
    }

    srand(time(NULL));
}