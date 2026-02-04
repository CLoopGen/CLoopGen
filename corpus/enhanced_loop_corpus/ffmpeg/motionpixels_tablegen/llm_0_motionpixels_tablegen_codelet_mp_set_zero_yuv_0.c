#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct YuvPixel {
    int8_t y;
    int8_t v;
    int8_t u;
} YuvPixel;

extern YuvPixel *p;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 31; ++i) {
    j = 31;
    for (; j > i; --j)
        if (!(p[j].u | p[j].v | p[j].y))
            p[j] = p[j - 1];
    j = 0;
    for (; j < 31 - i; ++j)
        if (!(p[j].u | p[j].v | p[j].y))
            p[j] = p[j + 1];
}
}
