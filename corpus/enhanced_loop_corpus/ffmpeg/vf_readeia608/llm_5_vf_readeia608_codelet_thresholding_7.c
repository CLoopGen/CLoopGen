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
for (int i = lag; i < len + lag; i++) {
    float value = line[i].input / 255.F;
    line[i].unfiltered = value;
    if (value > 0.1F) {
        line[i].filtered = value;
    } else {
        line[i].filtered = 0.0F;
    }
}
}
