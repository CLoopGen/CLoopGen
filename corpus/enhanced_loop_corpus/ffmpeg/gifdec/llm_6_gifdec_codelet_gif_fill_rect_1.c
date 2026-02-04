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
    uint32_t temp_color = color;
    for (; py < pb; py += linesize) {
        px = (uint32_t *)py + l;
        pr = px + w;
        for (; px < pr; px++) {
            *px = temp_color;
        }
    }
}
