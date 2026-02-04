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
    px = (uint32_t *)py + l;
    pr = px + w;
    for (; py < pb && px < pr; py += linesize, px += linesize) {
        *px = color;
        if (++px >= pr) px = (uint32_t *)py + l + linesize; // Simulate both loops in one with manual reset logic
    }
}
