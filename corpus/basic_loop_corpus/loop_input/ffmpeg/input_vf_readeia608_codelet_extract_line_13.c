#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct LineItem {
    int input;
    int output;
    float unfiltered;
    float filtered;
    float average;
    float deviation;
} LineItem;

int w;
LineItem *line;
int i;
uint8_t *src;

void init_vars() {
    w = 16777216; // ~16.7 million elements for ~0.01 sec runtime

    src = (uint8_t*)calloc(w, sizeof(uint8_t));
    if (!src) {
        exit(1);
    }

    for (int j = 0; j < w; j++) {
        src[j] = (uint8_t)(j % 256);
    }

    line = (LineItem*)calloc(w + 25, sizeof(LineItem));
    if (!line) {
        free(src);
        exit(1);
    }
}