#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define PLANE_SIZE (8 * 1024 * 1024) // 8MB per plane, total ~256MB for 32 planes

uint8_t *out[32];
uint8_t *in;
int i;
int plane_size;

void init_vars() {
    plane_size = PLANE_SIZE;
    in = aligned_alloc(32, plane_size * 32);
    if (!in) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int idx = 0; idx < 32; idx++) {
        out[idx] = NULL; // Initialize to NULL before loop
    }
}