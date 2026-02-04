#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int linesize;
extern  uint8_t color[4];
extern int k;
extern int start;
extern int end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride (access every second element in a strided pattern)
    int stride = 2;
    int j;
    for (j = start; j < end; j += stride) {
        buf[j * linesize] += color[0];
    }
}
