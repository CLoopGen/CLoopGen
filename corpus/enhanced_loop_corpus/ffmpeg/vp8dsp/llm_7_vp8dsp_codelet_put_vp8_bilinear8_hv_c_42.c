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
uint8_t prev_tmp_val = 0;
for (y = 0; y < h + 1; y++) {
    for (x = 0; x < 8; x++) {
        int base_val = (a * src[x] + b * src[x + 1] + 4) >> 3;
        tmp[x] = (base_val + prev_tmp_val) & 0xFF;
        prev_tmp_val = tmp[x]; 
    }
    tmp += 8;
    src += sstride;
}
}
