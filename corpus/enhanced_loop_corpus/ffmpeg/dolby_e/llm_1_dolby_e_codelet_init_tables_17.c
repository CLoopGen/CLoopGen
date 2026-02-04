#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float short_window3[64];
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            window[704 + i * 8 + j] = short_window3[i * 8 + j];
        }
    }
}
