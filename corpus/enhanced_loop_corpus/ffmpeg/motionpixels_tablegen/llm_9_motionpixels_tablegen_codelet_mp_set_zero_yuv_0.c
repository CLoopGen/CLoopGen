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
for (i = 0; i < 15; ++i) {
    for (j = 31; j > i * 2 && j > 0; --j) {
        int8_t sum = p[j].u + p[j].v;
        if (!(sum | p[j].y))
            p[j] = p[j - 1];
    }
    for (j = 0; j < 31 - i * 2; ++j) {
        int8_t avg = (p[j].u + p[j].v + p[j].y) / 3;
        if (avg == 0)
            p[j] = p[j + 1];
    }
}

}
