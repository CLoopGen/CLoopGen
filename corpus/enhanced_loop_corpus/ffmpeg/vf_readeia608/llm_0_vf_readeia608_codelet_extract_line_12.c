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
        int a = (i - 3) > 0 ? (i - 3) : 0;
        int b = (i - 2) > 0 ? (i - 2) : 0;
        int c = (i - 1) > 0 ? (i - 1) : 0;
        int d = (i + 3) > (w - 1) ? (w - 1) : (i + 3);
        int e = (i + 2) > (w - 1) ? (w - 1) : (i + 2);
        int f = (i + 1) > (w - 1) ? (w - 1) : (i + 1);
        line[25 + i].input = (src[a] + src[b] + src[c] + src[i] + src[d] + src[e] + src[f] + 6) / 7;
    }
}
