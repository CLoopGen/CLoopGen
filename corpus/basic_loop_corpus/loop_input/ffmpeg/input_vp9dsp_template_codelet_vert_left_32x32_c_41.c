#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *top;
int i;
uint8_t ve[31];
uint8_t vo[31];

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data
    top = (uint8_t*)malloc(data_size);
    if (!top) {
        exit(1);
    }
    for (size_t j = 0; j < data_size; j++) {
        top[j] = (uint8_t)(j * 71 % 251); // arbitrary but deterministic initialization
    }
}

// Ensure definitions are available for extern references
uint8_t *top;
int i;
uint8_t ve[31];
uint8_t vo[31];