#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define ARRAY_SIZE (1 << 20) // ~2MB total data, suitable for ~0.01 sec runtime

int16_t *top;
int16_t *bottom;
int i;
int a;
int b;
int c;
int d;
int d1;
int d2;
int rnd1;
int rnd2;

static int16_t top_array[ARRAY_SIZE];
static int16_t bottom_array[ARRAY_SIZE];

void init_vars() {
    // Initialize arrays to avoid undefined behavior
    for (int j = 0; j < ARRAY_SIZE; j++) {
        top_array[j] = (int16_t)(j & 0x1FF);
        bottom_array[j] = (int16_t)((j + 512) & 0x1FF);
    }

    // Set pointers so that accesses top[48], top[56], bottom[0], bottom[8] are valid
    // Ensure there's enough room for 8 iterations of pointer increments
    top = top_array + 48;
    bottom = bottom_array;

    // Initialize scalar variables
    i = 0;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    d1 = 0;
    d2 = 0;
    rnd1 = 3;
    rnd2 = 4;
}