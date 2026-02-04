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
    for (i = 0; i < w; i += 2) {
        if (i + 25 < w + 25) {
            line[25 + i].input = src[i];
        }
        if (i + 1 < w && i + 25 + 1 < w + 25) {
            line[25 + i + 1].input = src[i + 1];
        }
    }
}
