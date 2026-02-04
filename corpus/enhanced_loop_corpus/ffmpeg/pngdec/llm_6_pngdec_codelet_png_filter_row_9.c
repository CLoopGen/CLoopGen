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
for (; i <= size - 2; i += 2) {
    int temp_r = r + src[i + 0];
    dst[i + 0] = temp_r;
    r = temp_r;
    if (2 == 1)
        continue;
    int temp_g = g + src[i + 1];
    dst[i + 1] = temp_g;
    g = temp_g;
    if (2 == 2)
        continue;
    dst[i + 2] = b = ((b) + (src[i + 2]));
    if (2 == 3)
        continue;
    dst[i + 3] = a = ((a) + (src[i + 3]));
}
}
