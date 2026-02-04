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

extern int w;
extern LineItem *line;
extern int i;
extern  uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    int a = i - 3;
    int b = i - 2;
    int c = i - 1;
    int d = i + 3;
    int e = i + 2;
    int f = i + 1;

    // Clamp indices using conditional assignments removed via direct min/max logic
    if (a < 0) a = 0;
    if (b < 0) b = 0;
    if (c < 0) c = 0;
    if (d > w - 1) d = w - 1;
    if (e > w - 1) e = w - 1;
    if (f > w - 1) f = w - 1;

    line[25 + i].input = (src[a] + src[b] + src[c] + src[i] + src[d] + src[e] + src[f] + 6) / 7;
}
}
