#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *s1;
uint8_t *s2;
ptrdiff_t stride;
int h;
int score;
int x;
int y;

static uint8_t data1[1 << 20];
static uint8_t data2[1 << 20];

void init_vars() {
    stride = 16;
    h = 4096;
    score = 0;
    s1 = data1;
    s2 = data2;
}