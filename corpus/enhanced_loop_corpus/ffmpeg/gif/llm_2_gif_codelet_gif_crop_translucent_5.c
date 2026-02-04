#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int trans;
extern  int w;
extern int y_end;
extern int is_trans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reversed iteration
    for (int i = w - 1; i >= 0; i -= 2) {
        if (buf[linesize * y_end + i] != trans) {
            is_trans = 0;
            break;
        }
        // Handle odd-sized w by checking the previous element if within bounds
        if (i > 0 && buf[linesize * y_end + (i - 1)] != trans) {
            is_trans = 0;
            break;
        }
    }
}
