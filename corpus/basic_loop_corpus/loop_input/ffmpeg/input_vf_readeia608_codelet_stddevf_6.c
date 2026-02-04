#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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
float m;
float standard_deviation;

void init_vars() {
    len = 10000000; // Adjusted for ~0.01s runtime on modern CPU
    line = (LineItem*)aligned_alloc(32, len * sizeof(LineItem));
    if (!line) {
        exit(1);
    }

    for (int i = 0; i < len; i++) {
        line[i].input = i;
        line[i].output = i * 2;
        line[i].unfiltered = 1.5f * i;
        line[i].filtered = 1.0f + (i % 100) * 0.1f;
        line[i].average = 50.0f;
        line[i].deviation = 0.0f;
    }

    m = 50.0f;
    standard_deviation = 0.0f;
}