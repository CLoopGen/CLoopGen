#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            int idx = i * 256 + j;
            sum += flat_2d_array[idx] * flat_2d_array[idx]; // Squaring each element before accumulation
        }
    }
}
