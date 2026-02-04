#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *a;
uint8_t *b;
ptrdiff_t s;
int i;
int j;
int diff;

static uint8_t data_a[1 << 24];
static uint8_t data_b[1 << 24];

void init_vars() {
    s = 8;
    a = data_a;
    b = data_b;
    diff = 0;
}