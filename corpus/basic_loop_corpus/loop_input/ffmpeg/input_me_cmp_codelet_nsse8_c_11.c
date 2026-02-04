#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define TOTAL_SIZE (DATA_SIZE_MB * 1024ULL * 1024ULL)

uint8_t *s1;
uint8_t *s2;
ptrdiff_t stride;
int h;
int score1;
int score2;
int x;
int y;

void init_vars() {
    const size_t width = 32; 
    stride = width;
    h = TOTAL_SIZE / width;
    if (h < 1) h = 1;
    size_t total_bytes = (size_t)h * stride;

    s1 = aligned_alloc(32, total_bytes);
    s2 = aligned_alloc(32, total_bytes);

    if (!s1 || !s2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < total_bytes; i++) {
        s1[i] = (uint8_t)(rand() % 256);
        s2[i] = (uint8_t)(rand() % 256);
    }

    score1 = 0;
    score2 = 0;
    x = 0;
    y = 0;
}