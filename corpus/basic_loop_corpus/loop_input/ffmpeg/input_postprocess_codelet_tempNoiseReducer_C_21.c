#include <stdint.h>
#include <stdlib.h>

uint8_t *src;
int stride;
uint8_t *tempBlurred;
int y;

void init_vars() {
    stride = 128;
    int total_size = stride * 8;
    src = (uint8_t*)malloc(total_size);
    tempBlurred = (uint8_t*)malloc(total_size);

    for (int i = 0; i < total_size; i++) {
        src[i] = rand() % 256;
    }
}