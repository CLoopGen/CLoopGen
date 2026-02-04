#include <stdint.h>
#include <stddef.h>

uint8_t *src;
ptrdiff_t stride;
int sum;
int square_sum;
int y;
int x;

#define DATA_SIZE (128 * 1024 * 1024)
static uint8_t data[DATA_SIZE];

void init_vars() {
    stride = 8;
    src = data;
    sum = 0;
    square_sum = 0;
    y = 0;
    x = 0;
}