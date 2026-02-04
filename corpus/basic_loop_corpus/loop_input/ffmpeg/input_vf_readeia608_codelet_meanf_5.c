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

LineItem *line;
int len;
float sum;

void init_vars() {
    len = 1 << 20; // 1 million elements, roughly 24 MB of data (24 bytes per struct)
    line = (LineItem*)calloc(len, sizeof(LineItem));
    if (!line) {
        exit(1);
    }

    for (int i = 0; i < len; i++) {
        line[i].filtered = 1.0f + i * 0.001f; // Non-zero to ensure meaningful sum
    }

    sum = 0.0f;
}