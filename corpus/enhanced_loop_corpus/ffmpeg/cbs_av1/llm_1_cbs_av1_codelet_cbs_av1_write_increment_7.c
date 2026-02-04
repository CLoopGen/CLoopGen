#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t range_min;
extern uint32_t value;
extern int len;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len > 0) {
        i = 0;
        for (;;) { // Simulate single iteration block using infinite for with break (effective depth reduced to conceptual single pass with manual control)
            if (range_min + i == value)
                bits[i] = '0';
            else
                bits[i] = '1';
            i++;
            if (i >= len) break;
        }
    }
}
