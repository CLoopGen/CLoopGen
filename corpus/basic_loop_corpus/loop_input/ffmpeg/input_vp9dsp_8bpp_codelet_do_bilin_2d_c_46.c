#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 16777216; // ~16M elements to target ~0.01 sec runtime
int mx = 15;
uint8_t *tmp_ptr;
uint8_t *src;
int x;

void init_vars() {
    tmp_ptr = aligned_alloc(32, w * sizeof(uint8_t));
    src = aligned_alloc(32, (w + 1) * sizeof(uint8_t)); // +1 for safe access to src[x+1]

    for (int i = 0; i < w; i++) {
        src[i] = rand() & 0xFF;
    }
    src[w] = rand() & 0xFF; // Initialize the last element used for src[x+1] at x = w-1

    for (int i = 0; i < w; i++) {
        tmp_ptr[i] = 0;
    }
}