#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern volatile uint8_t in[1000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 1000; i++) {
        in[i] = i * i;
        if (i > 0)
            in[i] += in[i-1]; // Introduce RAW and WAW loop-carried dependency: each write depends on previous write
    }
}
