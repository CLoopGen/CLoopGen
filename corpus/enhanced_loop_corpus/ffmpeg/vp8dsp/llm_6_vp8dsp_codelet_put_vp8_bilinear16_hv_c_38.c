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
    uint8_t *tmp_base = tmp;
    uint8_t *src_base = src;
    for (y = 0; y < h + 1; y++) {
        ptrdiff_t offset = y * sstride;
        for (x = 0; x < 16; x++) {
            int val1 = (a * src_base[offset + x] + b * src_base[offset + x + 1] + 4) >> 3;
            int val2 = (x > 0) ? ((a * src_base[offset + x - 1] + b * src_base[offset + x] + 4) >> 3) : val1;
            tmp_base[y * 16 + x] = (x == 0) ? val1 : (val1 + val2) >> 1;
        }
    }
    tmp = tmp_base + (h + 1) * 16;
    src = src_base + (h + 1) * sstride;
}
