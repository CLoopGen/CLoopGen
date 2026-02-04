#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern volatile uint8_t in[1000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 1000; i += 4) {
        in[i]     = i * i;
        in[i + 1] = (i + 1) * (i + 1) + (i + 1);
        in[i + 2] = (i + 2) * (i + 2) - (i + 2);
        in[i + 3] = (i + 3) * (i + 3) + (i + 3) * 2;
    }
}
