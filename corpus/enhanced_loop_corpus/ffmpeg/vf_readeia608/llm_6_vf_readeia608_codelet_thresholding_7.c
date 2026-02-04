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

extern LineItem *line;
extern int lag;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev_filtered = 0.0F;
    for (int i = lag; i < len + lag; i++) {
        line[i].unfiltered = line[i].input / 255.F;
        line[i].filtered = line[i].unfiltered + prev_filtered;
        prev_filtered = line[i].filtered;
    }
}
