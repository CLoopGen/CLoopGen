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
    sum = 0.0f;
    for (int i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            sum += line[i].filtered + line[i+1].filtered;
        } else {
            sum += line[i].filtered;
        }
    }
}
