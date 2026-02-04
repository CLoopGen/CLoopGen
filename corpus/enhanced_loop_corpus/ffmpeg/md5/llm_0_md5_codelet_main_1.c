#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern volatile uint8_t in[1000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1000; j += 100) {
        for (i = j; i < j + 100 && i < 1000; i++) {
            in[i] = i % 127;
        }
    }
}
