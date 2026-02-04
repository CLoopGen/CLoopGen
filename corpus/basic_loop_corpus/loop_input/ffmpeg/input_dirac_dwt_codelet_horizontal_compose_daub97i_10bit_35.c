#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w2;
int x;
int b0;
int b1;
int b2;
int32_t *b;
int32_t *temp;

void init_vars() {
    w2 = 1 << 20; // Approximately 1MB of data: 2^20 elements
    size_t temp_size = w2 + w2; // Ensure we can access up to x + w2 safely
    size_t b_size = 2 * w2 + 1; // Index goes up to 2*x, with x < w2 -> max index ~ 2*w2

    temp = (int32_t*)calloc(temp_size, sizeof(int32_t));
    b = (int32_t*)calloc(b_size, sizeof(int32_t));

    for (size_t i = 0; i < temp_size; i++) {
        temp[i] = rand() & 0xFFFF;
    }

    b0 = 0;
    b1 = 0;
    b2 = 0;
    x = 0;
}