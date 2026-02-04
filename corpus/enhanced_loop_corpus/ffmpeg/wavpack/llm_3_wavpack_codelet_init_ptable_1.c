#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int value;
extern int rate;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int values[2];
    values[0] = value;
    values[1] = 0; // unused placeholder to simulate array access
    size_t index = 0;
    for (int c = (rate + 128) >> 8; c--;) {
        values[index] += (65536 - values[index]) >> 8;
    }
    value = values[0];
}
