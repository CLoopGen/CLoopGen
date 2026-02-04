#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t list[256];
uint8_t list_inv[256];
int counttab[256];
int (*counttab2)[256];
int i;
int x;
int y;

void init_vars() {
    // Initialize list and list_inv to zero
    memset(list, 0, sizeof(list));
    memset(list_inv, 0, sizeof(list_inv));

    // Initialize counttab with non-zero values to avoid division by zero
    for (int idx = 0; idx < 256; idx++) {
        counttab[idx] = 100 + (idx * 31); // Ensure positive values
    }

    // Allocate and initialize counttab2 as a 257x256 array to match access pattern [y+1][x] with y up to 255
    counttab2 = calloc(257, sizeof(int[256]));
    if (!counttab2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Seed random number generator for realistic data
    srand(time(NULL));

    // Fill counttab2 with small random values to simulate real scoring table
    for (int row = 0; row < 257; row++) {
        for (int col = 0; col < 256; col++) {
            counttab2[row][col] = rand() & 0xFF;
        }
    }

    // Initialize scalar loop indices
    i = 0;
    x = 0;
    y = 0;
}