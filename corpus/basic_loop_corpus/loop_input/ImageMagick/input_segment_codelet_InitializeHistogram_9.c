#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int Blue = 2;
int Green = 1;
int Red = 0;
ssize_t **histogram;
ssize_t i;

void init_vars() {
    const size_t HIST_SIZE = 256;
    const int NUM_COLORS = 3;

    histogram = (ssize_t**)calloc(NUM_COLORS, sizeof(ssize_t*));
    if (!histogram) exit(1);

    for (int c = 0; c < NUM_COLORS; c++) {
        histogram[c] = (ssize_t*)calloc(HIST_SIZE, sizeof(ssize_t));
        if (!histogram[c]) exit(1);
    }

    Blue = 2;
    Green = 1;
    Red = 0;
}