#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lwc_val[17] = { -600, -400, -300, -200, -100, 0, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 0 };

int* msk_val;

int i;

void init_vars() {
    size_t data_size = 1 << 20; // ~1MB of data (adjustable for timing)
    size_t num_elements = data_size / sizeof(int);
    
    // Ensure at least 16 elements for the loop
    if (num_elements < 16) {
        num_elements = 16;
    }

    msk_val = (int*)calloc(num_elements, sizeof(int));
    
    if (!msk_val) {
        exit(1);
    }
    
    // Initialize first 16 elements to known values for predictable behavior
    for (int j = 0; j < 16; j++) {
        msk_val[j] = j * 10;
    }
}