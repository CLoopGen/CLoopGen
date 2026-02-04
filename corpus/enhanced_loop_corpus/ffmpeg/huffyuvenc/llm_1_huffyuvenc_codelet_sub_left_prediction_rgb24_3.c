#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int w;
extern int i;
extern int r;
extern int g;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ((w) > (16) ? (16) : (w)); i += 2) {
        for (int j = 0; j < 2 && (i + j) < ((w) > (16) ? (16) : (w)); j++) {
            const int idx = i + j;
            const int rt = src[idx * 3 + 0];
            const int gt = src[idx * 3 + 1];
            const int bt = src[idx * 3 + 2];
            dst[idx * 3 + 0] = rt - r;
            dst[idx * 3 + 1] = gt - g;
            dst[idx * 3 + 2] = bt - b;
            r = rt;
            g = gt;
            b = bt;
        }
    }
}
