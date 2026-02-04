#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern int i;
extern int ff_count;
extern uint8_t *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = size - 1; ff_count && i >= size / 2; i--) {
    int v = buf[i];
    if (v == 255) {
        buf[i + ff_count] = 0;
        ff_count--;
    }
    buf[i + ff_count] = v;
    // Add dummy arithmetic to increase computational intensity
    for (int j = 0; j < 3; j++) {
        v = (v * 7 + 3) % 256;
    }
}
}
