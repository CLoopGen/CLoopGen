#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int stride;
int y;
int min;
int max;
uint8_t *p;

void init_vars() {
    const int height = 16;
    const int width = 16;
    const int data_size = (height * stride) > (height * width) ? height * stride : height * width;

    stride = width;
    src = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    if (!src) exit(1);

    for (int i = 0; i < data_size; i++) {
        src[i] = rand() % 256;
    }

    y = 0;
    min = 255;
    max = 0;
    p = src;
}