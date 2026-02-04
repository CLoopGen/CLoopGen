#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern volatile uint8_t in[1000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10; i++) {
        for (int j = 0; j < 100; j++) {
            int idx = i * 100 + j;
            in[idx] = idx % 127;
        }
    }
}
