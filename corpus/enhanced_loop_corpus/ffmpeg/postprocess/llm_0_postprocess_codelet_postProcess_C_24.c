#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t * yHistogram;
extern uint64_t sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < 256; i++) {
            sum += yHistogram[i];
        }
    }
}
