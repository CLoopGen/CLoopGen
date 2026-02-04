#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern volatile uint8_t in[1000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 1000; i += 4) {
        in[i] = i % 127;
        if (i + 1 < 1000) in[i + 1] = (i + 1) % 127;
        if (i + 2 < 1000) in[i + 2] = (i + 2) % 127;
        if (i + 3 < 1000) in[i + 3] = (i + 3) % 127;
    }
}
