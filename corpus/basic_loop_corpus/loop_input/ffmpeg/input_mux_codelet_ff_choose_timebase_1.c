#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVRational {
    int num;
    int den;
} AVRational;

int min_precision;
AVRational q;
int j;

void init_vars() {
    min_precision = 10;
    q.num = 12345678;
    q.den = 123456;
}