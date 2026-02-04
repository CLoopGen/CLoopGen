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

extern int w;
extern LineItem *line;
extern int i;
extern  uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < w - 1; i++) {
        int sum = 0;
        for (int offset = -2; offset <= 2; offset++) {
            int idx = i + offset;
            sum += src[idx];
        }
        line[25 + i].input = (sum + 2) / 5; // Simpler average over 5 elements, reduced arithmetic overhead
    }
}
