#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern volatile uint8_t in[1000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int stride = 7;
    for (i = 0; i < 1000; i++) {
        int index = (i * stride) % 1000;
        in[index] = i % 127;
    }
}
