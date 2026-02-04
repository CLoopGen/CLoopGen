#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int min;
extern unsigned int max;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal of the array
    unsigned int i;
    for (i = (max > 16 ? 15 : max - 1); i >= 1; i--) {
        if (count[i] != 0) {
            min = i;
            break;
        }
    }
}
