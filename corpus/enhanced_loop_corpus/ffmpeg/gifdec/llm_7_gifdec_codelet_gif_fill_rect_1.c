#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t color;
extern int l;
extern int w;
extern  int linesize;
extern  uint32_t *py;
extern  uint32_t *pr;
extern  uint32_t *pb;
extern uint32_t *px;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_color = color ^ 0x1; // Introduce minor variation to break direct WAW dependency
    for (; py < pb; py += linesize) {
        px = (uint32_t *)py + l;
        pr = px + w;
        if (local_color & 1) {
            for (; px < pr; px++)
                *px = local_color;
        } else {
            for (; px < pr; px++)
                *px = local_color + 1;
        }
    }
}
