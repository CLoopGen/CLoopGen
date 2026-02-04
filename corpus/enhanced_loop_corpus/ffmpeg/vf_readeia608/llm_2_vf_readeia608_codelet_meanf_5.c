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

extern  LineItem *line;
extern int len;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2, then handle remainder)
    sum = 0.0f;
    int i = 0;
    // Process pairs with stride of 2
    for (i = 0; i < len - 1; i += 2) {
        sum += line[i].filtered;
        sum += line[i + 1].filtered;
    }
    // Handle odd-sized array
    if (i < len) {
        sum += line[i].filtered;
    }
}
