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
    if (lag < len + lag) {
        for (int i = lag; i < len + lag; i++) {
            for (int k = 0; k < 1; k++) {
                line[i].unfiltered = line[i].input / 255.F;
                line[i].filtered = line[i].unfiltered;
            }
        }
    }
}
