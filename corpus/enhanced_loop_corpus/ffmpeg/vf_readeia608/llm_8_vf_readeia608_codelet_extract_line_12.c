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
    for (i = 0; i < w; i += 2) {
        if (i + 1 >= w) break;
        int a1 = (i - 3) > 0 ? i - 3 : 0;
        int b1 = (i - 2) > 0 ? i - 2 : 0;
        int c1 = (i - 1) > 0 ? i - 1 : 0;
        int d1 = (i + 3) < w - 1 ? i + 3 : w - 1;
        int e1 = (i + 2) < w - 1 ? i + 2 : w - 1;
        int f1 = (i + 1) < w - 1 ? i + 1 : w - 1;

        int a2 = (i + 1 - 3) > 0 ? i + 1 - 3 : 0;
        int b2 = (i + 1 - 2) > 0 ? i + 1 - 2 : 0;
        int c2 = (i + 1 - 1) > 0 ? i + 1 - 1 : 0;
        int d2 = (i + 1 + 3) < w - 1 ? i + 1 + 3 : w - 1;
        int e2 = (i + 1 + 2) < w - 1 ? i + 1 + 2 : w - 1;
        int f2 = (i + 1 + 1) < w - 1 ? i + 1 + 1 : w - 1;

        line[25 + i].input = (src[a1] + src[b1] + src[c1] + src[i] + src[d1] + src[e1] + src[f1] + 6) / 7;
        line[25 + i + 1].input = (src[a2] + src[b2] + src[c2] + src[i + 1] + src[d2] + src[e2] + src[f2] + 6) / 7;
    }
}
