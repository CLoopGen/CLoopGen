#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float short_window2[192];
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write using pointer arithmetic and incremental step of 3, unrolled-like pattern (simulated strided read)
    float *win_ptr = &window[448];
    for (i = 0; i < 192; i += 3) {
        win_ptr[i]     = short_window2[i];
        if (i+1 < 192) win_ptr[i+1] = short_window2[i+1];
        if (i+2 < 192) win_ptr[i+2] = short_window2[i+2];
    }
}
