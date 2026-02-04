#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 56; i++) {
        for (int j = 0; j < 8; j++) {
            int idx = i * 8 + j;
            window[3264 + idx] = window[1407 - idx];
        }
    }
}
