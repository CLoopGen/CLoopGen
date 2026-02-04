#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int stride;
int size;
int k;
int t;
uint8_t colors[2];
int8_t *pglyph;

void init_vars() {
    size = 1024; // Choose size so that total memory accessed is about size^2 = 1M elements
    stride = size;
    
    // Allocate dst buffer of size stride * size
    dst = (uint8_t *)aligned_alloc(32, stride * size * sizeof(uint8_t));
    
    // Allocate pglyph buffer of size size * size (needed for all iterations)
    pglyph = (int8_t *)aligned_alloc(32, size * size * sizeof(int8_t));
    
    // Initialize colors
    colors[0] = 0xAA;
    colors[1] = 0x55;
    
    // Initialize pglyph with random 0 and 1 values to simulate glyph data
    for (int i = 0; i < size * size; i++) {
        pglyph[i] = rand() & 1;
    }
    
    // Initialize other variables
    k = 0;
    t = 0;
}