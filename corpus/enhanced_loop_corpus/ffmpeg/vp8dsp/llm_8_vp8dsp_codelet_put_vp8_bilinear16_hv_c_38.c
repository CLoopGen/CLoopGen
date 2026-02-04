#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t sstride;
extern int h;
extern int a;
extern int b;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h + 1; y++) {
    for (x = 0; x < 16; x++) {
        int val1 = src[x];
        int val2 = src[x + 1];
        int product1 = a * val1;
        int product2 = b * val2;
        int sum = product1 + product2 + 8;
        int shifted = sum >> 4;
        tmp[x] = (uint8_t)shifted;
    }
    tmp += 16;
    src += sstride;
}
}
