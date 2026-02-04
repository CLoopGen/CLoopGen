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
    if (w > 0) {
        i = 0;
        for (; i < w; ) {
            line[25 + i].input = src[i];
            i++;
        }
    }
}
