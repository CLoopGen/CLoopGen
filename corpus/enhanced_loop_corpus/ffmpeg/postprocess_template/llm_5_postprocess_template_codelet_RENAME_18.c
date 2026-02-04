#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t * yHistogram;
extern uint64_t sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; ++i) {
        if (i % 2 == 0) {
            sum += yHistogram[i];
        } else {
            continue;
        }
    }
}
