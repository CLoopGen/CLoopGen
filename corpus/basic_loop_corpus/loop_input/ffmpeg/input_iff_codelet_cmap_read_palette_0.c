#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t *pal;
int count;
int i;
uint8_t *palette;

void init_vars() {
    count = 65536; // Enough iterations to take ~0.01s
    pal = (uint32_t *)malloc(count * sizeof(uint32_t));
    palette = (uint8_t *)malloc(count * 3 * sizeof(uint8_t));

    for (int j = 0; j < count * 3; j++) {
        palette[j] = rand() % 256;
    }

    i = 0;
}