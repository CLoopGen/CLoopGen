#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int Alphabet_size;
float *null;
int x;

void init_vars() {
    Alphabet_size = 65536;  // Size chosen so that null array is ~256KB, loop runs in ~0.01s
    null = (float*)calloc(Alphabet_size, sizeof(float));
    if (!null) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    x = 0;
}