#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int nb_pixel;

uint8_t *pixel_data;

void init_vars() {
    nb_pixel = 67108864; // 64 million pixels -> nb_pixel/4 = 16.7M loop iterations, approx 0.01 sec on modern CPU
    pixel_data = (uint8_t*)aligned_alloc(32, nb_pixel * sizeof(uint8_t));
    if (!pixel_data) {
        exit(1);
    }
    for (int idx = 0; idx < nb_pixel; idx++) {
        pixel_data[idx] = (uint8_t)(idx % 256);
    }
}