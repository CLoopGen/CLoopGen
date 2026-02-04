#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float short_window2[192];
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 192; i++) {
        if (!(short_window2[i] <= 0.0f)) {
            window[448 + i] = short_window2[i];
        } else {
            window[448 + i] = 0.0f;
        }
    }
}
