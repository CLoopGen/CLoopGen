#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *top;
int i;
uint8_t ve[15];
uint8_t vo[15];

static uint8_t *allocated_top;

void init_vars() {
    size_t data_size = 16777216; // ~16MB to target ~0.01s runtime
    allocated_top = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    
    if (!allocated_top) {
        exit(1);
    }
    
    for (size_t j = 0; j < data_size; j++) {
        allocated_top[j] = (uint8_t)(j % 251);
    }
    
    top = allocated_top;
    
    for (int k = 0; k < 15; k++) {
        ve[k] = 0;
        vo[k] = 0;
    }
    
    i = 0;
}