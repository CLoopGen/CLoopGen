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
    if (py >= pb || linesize <= 0) return;
    for (; py < pb; py += linesize) {
        px = (uint32_t *)py + l;
        pr = px + w;
        for (; px < pr; px++) {
            if ((uintptr_t)(px) % sizeof(uint32_t) == 0)
                *px = color;
        }
    }
}
