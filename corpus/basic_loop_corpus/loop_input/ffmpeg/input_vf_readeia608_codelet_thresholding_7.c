#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef struct LineItem {
    int input;
    int output;
    float unfiltered;
    float filtered;
    float average;
    float deviation;
} LineItem;

LineItem *line;
int lag;
int len;

void init_vars() {
    len = 10000000;  
    lag = 1000;      

    line = (LineItem*)aligned_alloc(32, (len + lag) * sizeof(LineItem));
    if (!line) {
        exit(1);
    }

    for (int i = 0; i < len + lag; i++) {
        line[i].input = rand() % 1000;
        line[i].output = 0;
        line[i].unfiltered = 0.0f;
        line[i].filtered = 0.0f;
        line[i].average = 0.0f;
        line[i].deviation = 0.0f;
    }
}