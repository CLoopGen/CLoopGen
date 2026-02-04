#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB total data

uint8_t *s1;
uint8_t *s2;
ptrdiff_t stride;
int h;
int score1;
int score2;
int x;
int y;

static uint8_t buffer1[DATA_SIZE];
static uint8_t buffer2[DATA_SIZE];

void init_vars() {
    const int width = 16;
    stride = width + 1; // Ensure some padding to allow for stride access
    h = DATA_SIZE / stride / 2; // Adjust height so we don't overflow buffer
    if (h > 10000) h = 10000; // Limit to reasonable number of iterations

    // Make sure we can access s1[x + stride + 1] safely when x=14 and y < h-1
    while ((h - 1) * stride + 15 + stride + 1 >= DATA_SIZE / 2) {
        h--;
    }

    // Initialize buffers with non-zero values for meaningful computation
    srand(time(NULL));
    for (size_t i = 0; i < DATA_SIZE; i++) {
        buffer1[i] = rand() & 0xFF;
        buffer2[i] = rand() & 0xFF;
    }

    s1 = buffer1;
    s2 = buffer2;
    score1 = 0;
    score2 = 0;
    x = 0;
    y = 0;
}