#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 2; j++) {
        for (i = 0; i < 128; i++) {
            int index = 2304 + i + j * 128;
            int mirror = 1663 - i - j * 128;
            window[index] = window[1152 + i + j * 128] = window[mirror];
        }
    }
}
