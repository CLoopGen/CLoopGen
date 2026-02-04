#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *s1;
uint8_t *s2;
ptrdiff_t stride;
int h;
int score;
int x;
int y;

#define DATA_SIZE (128 << 20) // 128 MB

static uint8_t buffer1[DATA_SIZE];
static uint8_t buffer2[DATA_SIZE];

void init_vars() {
    const int width = 8;
    const int height = (DATA_SIZE / width); 

    h = height;
    stride = width * sizeof(uint8_t);
    score = 0;

    s1 = buffer1;
    s2 = buffer2;

    for (int i = 0; i < DATA_SIZE; i++) {
        buffer1[i] = rand() & 0xFF;
        buffer2[i] = rand() & 0xFF;
    }
}