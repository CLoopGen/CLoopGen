#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 256 * 256; i++) {
        if (flat_2d_array[i] > 0) {
            sum += flat_2d_array[i];
        }
    }
}
