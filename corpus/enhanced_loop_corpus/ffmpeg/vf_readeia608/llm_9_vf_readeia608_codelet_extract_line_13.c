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
    float sum = 0.0f;
    for (i = 0; i < w; i++) {
        line[25 + i].input = src[i];
        line[25 + i].unfiltered = (float)src[i] * 1.05f;
        line[25 + i].filtered = line[25 + i].unfiltered * 0.9f;
        sum += line[25 + i].filtered;
    }
    for (i = 0; i < w; i++) {
        line[25 + i].average = sum / w;
        line[25 + i].deviation = line[25 + i].filtered - line[25 + i].average;
    }
}
