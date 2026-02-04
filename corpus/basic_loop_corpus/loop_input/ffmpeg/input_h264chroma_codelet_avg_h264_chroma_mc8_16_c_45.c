#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t stride;
int h;
uint16_t *dst;
uint16_t *src;
int A = 15;
int B = 25;
int C = 30;
int D = 35;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * (1 << 20)) / sizeof(uint16_t))
#define ROWS (TOTAL_ELEMENTS / 18)
#define COLS 18

static uint16_t *dst_buffer;
static uint16_t *src_buffer;

void init_vars() {
    const unsigned seed = 12345;
    srand(seed);

    A = rand() % 10 + 10;
    B = rand() % 10 + 10;
    C = rand() % 10 + 10;
    D = rand() % 10 + 10;

    h = ROWS > 1000 ? 1000 : ROWS;

    stride = COLS;

    dst_buffer = aligned_alloc(32, TOTAL_ELEMENTS * sizeof(uint16_t));
    src_buffer = aligned_alloc(32, TOTAL_ELEMENTS * sizeof(uint16_t));

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < TOTAL_ELEMENTS; i++) {
        src_buffer[i] = rand() & 0x3FF;
        dst_buffer[i] = rand() & 0x3FF;
    }

    dst = dst_buffer;
    src = src_buffer;
}