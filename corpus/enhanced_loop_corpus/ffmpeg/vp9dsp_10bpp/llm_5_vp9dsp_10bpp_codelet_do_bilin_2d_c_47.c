#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int mx;
extern uint16_t *tmp_ptr;
extern  uint16_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w; x++) {
        int next_idx = x + 1;
        if (next_idx >= w) continue;
        int diff = src[next_idx] - src[x];
        int adjusted = (mx * diff + 8) >> 4;
        tmp_ptr[x] = src[x] + adjusted;
    }
}
