#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

int8_t *pix1;
int16_t *pix2;
intptr_t size;
int score;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

    pix1 = (int8_t*)aligned_alloc(32, data_size * sizeof(int8_t));
    pix2 = (int16_t*)aligned_alloc(32, data_size * sizeof(int16_t));

    if (!pix1 || !pix2) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    size = (intptr_t)data_size;
    score = 0;
    i = 0;

    srand((unsigned int)time(NULL));
    for (size_t j = 0; j < data_size; j++) {
        pix1[j] = (int8_t)(rand() % 256 - 128);
        pix2[j] = (int16_t)(rand() % 65536 - 32768);
    }
}