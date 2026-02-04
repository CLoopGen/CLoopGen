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
        line[i].unfiltered = line[i].input / 255.F;
        line[i].filtered = (line[i].unfiltered + line[i].unfiltered * 0.1F) * 0.9F;
        line[i].average = (line[i].unfiltered + line[i > lag ? i - 1 : i].unfiltered) * 0.5F;
        line[i].deviation = line[i].filtered - line[i].average;
    }
}
