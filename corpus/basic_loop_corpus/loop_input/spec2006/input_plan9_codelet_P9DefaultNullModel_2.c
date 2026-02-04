#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int Alphabet_size = 1048576; // 1MB / sizeof(float) * 4, ~1M elements for ~0.01 sec
float *null;
int x;

void init_vars() {
    null = (float*)calloc(Alphabet_size, sizeof(float));
}