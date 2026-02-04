#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

__attribute__((aligned(32))) float window[3712];

int i;

void init_vars() {
    // Initialize the window array to avoid undefined behavior when reading
    for (int idx = 0; idx < 3712; idx++) {
        window[idx] = 0.0F;
    }
    // Ensure i is initialized to a known state before any potential use
    i = 0;
}