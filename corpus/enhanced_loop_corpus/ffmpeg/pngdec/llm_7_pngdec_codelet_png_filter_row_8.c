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
int local_b = b;
int local_a = a;
for (; i <= size - 1; i += 4) {
    dst[i + 0] = local_r = local_r + src[i + 0];
    dst[i + 1] = local_g = local_g + src[i + 1];
    dst[i + 2] = local_b = local_b + src[i + 2];
    dst[i + 3] = local_a = local_a + src[i + 3];
}
r = local_r;
g = local_g;
b = local_b;
a = local_a;
}
