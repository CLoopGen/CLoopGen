#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t number_planes = 134217728; // 128MB to target ~0.01 sec runtime on modern CPU
ssize_t i;
unsigned char background_color[256];

void init_vars() {
    if (number_planes > 256) {
        number_planes = 256;
    }
    for (size_t j = 0; j < number_planes; j++) {
        background_color[j] = rand() % 256;
    }
}