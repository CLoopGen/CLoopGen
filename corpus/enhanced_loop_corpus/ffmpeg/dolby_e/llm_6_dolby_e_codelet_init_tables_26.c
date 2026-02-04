#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 448; i += 2) {
        window[3264 + i] = window[1407 - i];
        if (i + 1 < 448)
            window[3264 + i + 1] = window[1407 - i - 1];
    }
}
