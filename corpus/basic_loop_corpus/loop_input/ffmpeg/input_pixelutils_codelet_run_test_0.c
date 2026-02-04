#include <stdlib.h>
#include <stdint.h>

uint8_t *b1;
uint8_t *b2;
int a;

static uint8_t data1[256 << 20]; // 256 MB
static uint8_t data2[256 << 20]; // 256 MB

void init_vars() {
    b1 = data1;
    b2 = data2;
}