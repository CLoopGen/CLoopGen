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
    for (x = 0; x < 4; x++) {
        int val1 = src[x];
        int val2 = src[x + 1];
        int product_a = a * val1;
        int product_b = b * val2;
        int sum = product_a + product_b + 8;
        int result = (sum + (sum >> 31)) >> 4; // Arithmetic right shift with rounding toward zero
        tmp[x] = (uint8_t)result;
    }
    tmp += 4;
    src += sstride;
}
}
