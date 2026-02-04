#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern volatile uint8_t in[1000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 1000; ++i) {
        if (i < 500)
            in[i] = i * i;
        else
            in[i] = (1000 - i) * (1000 - i);
    }
}
