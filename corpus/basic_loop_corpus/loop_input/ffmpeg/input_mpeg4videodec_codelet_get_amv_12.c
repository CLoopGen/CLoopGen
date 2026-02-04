#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
int y;
int mb_v;
int sum;
int dx;
int dy;
int shift;

void init_vars() {
    mb_v = 0x1000;
    dx = 0x80;
    dy = 0x40;
    shift = 4;
    sum = 0;
}