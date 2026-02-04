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
    w = 1 << 24; // 16.7 million elements, roughly 64 MB for src, ~268 MB for line
    src = (uint8_t*)calloc(w + 6, sizeof(uint8_t)); // extra padding to prevent out-of-bounds
    if (!src) exit(1);

    line = (LineItem*)calloc(w + 50, sizeof(LineItem)); // ensure 25+w is valid
    if (!line) exit(1);
}
