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
    for (x = 0; x < 8; x++) {
        int val1 = src[x];
        int val2 = src[x + 1];
        int prod1 = a * val1;
        int prod2 = b * val2;
        int sum = prod1 + prod2 + 4;
        tmp[x] = sum >> 3;
    }
    tmp += 8;
    src += sstride;
}
}
