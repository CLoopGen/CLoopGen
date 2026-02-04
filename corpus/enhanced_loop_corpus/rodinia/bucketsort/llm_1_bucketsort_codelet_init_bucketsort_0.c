#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < (1 << 8); i++) {
        for (int j = 0; j < (1 << 2); j++) {
            h_offsets[(i << 2) | j] = 0;
        }
    }
}
