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
int local_r = r;
int local_g = g;
for (; i <= size - 2; i += 2) {
    local_r = local_r + src[i + 0];
    dst[i + 0] = local_r;
    if (2 == 1)
        continue;
    local_g = local_g + src[i + 1];
    dst[i + 1] = local_g;
    if (2 == 2)
        continue;
    dst[i + 2] = b = ((b) + (src[i + 2]));
    if (2 == 3)
        continue;
    dst[i + 3] = a = ((a) + (src[i + 3]));
}
r = local_r;
g = local_g;
}
