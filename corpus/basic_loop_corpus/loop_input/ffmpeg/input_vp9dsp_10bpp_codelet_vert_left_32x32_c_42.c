#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint16_t *top;
int i;
uint16_t ve[31];
uint16_t vo[31];

void init_vars() {
    const size_t data_size = 256 * 1024 * sizeof(uint16_t);
    top = aligned_alloc(32, data_size);
    
    if (!top) {
        exit(1);
    }
    
    for (size_t idx = 0; idx < data_size / sizeof(uint16_t); ++idx) {
        top[idx] = rand() & 0xFFFF;
    }
    
    for (int j = 0; j < 31; ++j) {
        ve[j] = 0;
        vo[j] = 0;
    }
    i = 0;
}