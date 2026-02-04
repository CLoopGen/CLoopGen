#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t * yHistogram;
extern uint64_t sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; i += 4) {
        sum += yHistogram[i];
        if (i + 1 < 256) sum += yHistogram[i + 1];
        if (i + 2 < 256) sum += yHistogram[i + 2];
        if (i + 3 < 256) sum += yHistogram[i + 3];
    }
}
