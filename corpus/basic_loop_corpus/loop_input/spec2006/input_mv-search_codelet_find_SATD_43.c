#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (128 * 1024 * 1024) // ~128 MB for ~0.01 sec runtime target

int *byte_abs;
int i;
int sad;
int block_size_x;
int block_size_y;
int diff[256];

void init_vars() {
    // Set block dimensions so that total elements fits within diff array size (256)
    block_size_x = 16;
    block_size_y = 16;
    i = 0;
    sad = 0;

    // Allocate and initialize byte_abs lookup table for absolute values
    // Assuming byte_abs maps index to its absolute value (though diff may contain signed bytes)
    byte_abs = (int*)calloc(257, sizeof(int)); // indices -1 to 255 -> offset by +1
    if (!byte_abs) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    for (int idx = 0; idx <= 256; idx++) {
        int val = idx - 1; // represent values from -1 to 255
        byte_abs[idx] = (val < 0) ? -val : val;
    }

    // Initialize diff with sample data in valid range [-1, 255] to match byte_abs indexing
    srand(time(NULL));
    for (int j = 0; j < 256; j++) {
        diff[j] = (rand() % 3) - 1; // mostly -1, 0, 1
    }
}