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
    // Variant 2: Reverse consecutive memory access
    sum = 0.0f;
    for (int i = len - 1; i >= 0; i--) {
        sum += line[i].filtered;
    }
}
