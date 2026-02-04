#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern volatile uint8_t in[1000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 500; i++) {
        in[i * 2] = i * i;
        in[i * 2 + 1] = (i + 1) * (i + 1);
    }
}
