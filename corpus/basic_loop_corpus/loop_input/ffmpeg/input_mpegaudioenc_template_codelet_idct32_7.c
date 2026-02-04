#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define TAB_SIZE 32
#define XP_SIZE 8

int *tab;
int i;
int xr;
int *xp;

static int tab_storage[TAB_SIZE];
static int xp_storage[XP_SIZE];

void init_vars() {
    // Initialize tab to non-zero values to avoid trivial optimizations
    for (int idx = 0; idx < TAB_SIZE; ++idx) {
        tab_storage[idx] = rand() & 0xFFFF;
    }
    
    // Initialize xp with non-zero coefficients
    for (int idx = 0; idx < XP_SIZE; ++idx) {
        xp_storage[idx] = (rand() & 0x7FFF) + 1;
    }

    // Set global pointers to point to storage
    tab = tab_storage;
    xp = xp_storage;
    i = 0;
    xr = 0;
}