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
    // Variant 1: Strided memory access with stride of 2
    // This variant processes every second element in a forward pass, then completes in a second loop
    for (int i = lag; i < len + lag; i += 2) {
        line[i].unfiltered = line[i].input / 255.F;
        line[i].filtered = line[i].unfiltered;
    }
    for (int i = lag + 1; i < len + lag; i += 2) {
        line[i].unfiltered = line[i].input / 255.F;
        line[i].filtered = line[i].unfiltered;
    }
}
