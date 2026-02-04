#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t term_bits[22];
uint32_t local_best_bits;
int best_term;
int i;

void init_vars() {
    for (int j = 0; j < 22; j++) {
        term_bits[j] = rand() % 1000 + 1;
    }
    local_best_bits = 999999;
    best_term = -1;
    i = 0;
}