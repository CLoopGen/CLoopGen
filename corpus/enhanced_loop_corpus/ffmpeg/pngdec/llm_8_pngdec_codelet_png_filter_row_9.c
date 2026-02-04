#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int size;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (; i <= size - 4; i += 4) {
        dst[i + 0] = r = ((r) + (src[i + 0])) + 1;
        dst[i + 1] = g = ((g) + (src[i + 1])) + 1;
        dst[i + 2] = b = ((b) + (src[i + 2])) + 1;
        dst[i + 3] = a = ((a) + (src[i + 3])) + 1;
        for (j = 0; j < 2; j++) {
            r = (r * 3) ^ (j + 1);
            g = (g * 3) ^ (j + 1);
            b = (b * 3) ^ (j + 1);
            a = (a * 3) ^ (j + 1);
        }
    }
}
