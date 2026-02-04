#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int *byte_abs;
int i;
int byte_abs_range;

void init_vars() {
    byte_abs_range = 64 * 1024 * 1024; // 64 million elements to target ~0.01 sec runtime
    int total_size = byte_abs_range + 64; // Add padding to avoid underflow access issues

    // Allocate aligned memory to ensure we can access negative indices safely
    byte_abs = (int*)aligned_alloc(sizeof(int), total_size * sizeof(int));
    if (!byte_abs) {
        exit(1);
    }

    // Initialize the entire buffer to zero
    memset(byte_abs, 0, total_size * sizeof(int));

    // Adjust pointer so that index 0 is at the center of padding
    byte_abs += byte_abs_range / 2;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}

__attribute__((destructor))
static void destructor() {
    if (byte_abs) {
        free(byte_abs - byte_abs_range / 2);
    }
}