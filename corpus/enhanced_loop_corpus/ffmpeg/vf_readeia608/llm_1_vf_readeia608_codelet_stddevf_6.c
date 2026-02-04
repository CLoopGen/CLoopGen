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
extern float m;
extern float standard_deviation;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < len; j += 2) {
        float sum_partial = 0.0f;
        for (int k = j; k < len && k < j + 2; k++) {
            float diff = line[k].filtered - m;
            sum_partial += diff * diff;
        }
        standard_deviation += sum_partial;
    }
}
