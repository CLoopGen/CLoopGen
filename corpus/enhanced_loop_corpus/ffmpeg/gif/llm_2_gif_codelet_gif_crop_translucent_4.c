#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int *y_start;
extern int trans;
extern  int w;
extern int is_trans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride (access every 2nd element)
    for (int i = 0; i < w; i += 2) {
        if (buf[linesize * *y_start + i] != trans) {
            is_trans = 0;
            break;
        }
        // Handle odd index if needed, but ensure bounds
        if (i + 1 < w && buf[linesize * *y_start + i + 1] != trans) {
            is_trans = 0;
            break;
        }
    }
}
