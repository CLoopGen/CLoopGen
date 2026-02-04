#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int linesize;
extern  uint8_t color[4];
extern int k;
extern  int start;
extern  int end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increasing stride over iterations
    int stride = 1;
    for (int j = start; j < end; j++) {
        int index = (j * stride) % linesize; // Strided access within line bounds
        buf[j * linesize + index] += color[0];
        stride = (stride * 7) % 100; // Pseudo-random stride variation
    }
}
