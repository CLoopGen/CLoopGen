#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0.0f;
    for (int i = 0; i < 256 * 256; i += 4) {
        sum += flat_2d_array[i];
        if (i + 1 < 256 * 256) sum += flat_2d_array[i + 1];
        if (i + 2 < 256 * 256) sum += flat_2d_array[i + 2];
        if (i + 3 < 256 * 256) sum += flat_2d_array[i + 3];
    }
}
