#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *block;
ptrdiff_t stride;
uint32_t cm;
int x;
int y;
int w1tab[4];
int prods[4];
int at1_r;
int at1_g;
int at1_b;
int at2_r;
int at2_g;
int at2_b;
int akku;

void init_vars() {
    cm = 0xAAAAAAAA; // Ensure enough bits for 16 iterations (4x4)
    
    w1tab[0] = 1;
    w1tab[1] = 2;
    w1tab[2] = 3;
    w1tab[3] = 4;
    
    prods[0] = 10;
    prods[1] = 20;
    prods[2] = 30;
    prods[3] = 40;
    
    at1_r = 0;
    at1_g = 0;
    at1_b = 0;
    at2_r = 0;
    at2_g = 0;
    at2_b = 0;
    akku = 0;
    
    stride = 64;
    size_t total_size = stride * 64;
    block = aligned_alloc(64, total_size);
    if (!block) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    memset(block, 0x5A, total_size);
}