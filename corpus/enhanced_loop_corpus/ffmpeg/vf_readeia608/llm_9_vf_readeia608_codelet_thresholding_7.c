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
    for (int i = lag; i < len + lag && i < lag + 100; i += 2) {
        float inv_255 = 1.0F / 255.0F;
        float u1 = line[i].input * inv_255;
        float u2 = (i + 1 < len + lag) ? line[i + 1].input * inv_255 : u1;
        line[i].unfiltered = u1;
        line[i].filtered = u1;
        if (i + 1 < len + lag) {
            line[i + 1].unfiltered = u2;
            line[i + 1].filtered = u2;
        }
    }
}
