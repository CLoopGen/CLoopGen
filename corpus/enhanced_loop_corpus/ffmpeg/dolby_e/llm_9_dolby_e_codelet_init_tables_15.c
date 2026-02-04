#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float short_window2[192];
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        window[448 + i * 3] = short_window2[i * 3];
        window[448 + i * 3 + 1] = short_window2[i * 3 + 1] + 0.1f;
        window[448 + i * 3 + 2] = short_window2[i * 3 + 2] - 0.1f;
    }
}
