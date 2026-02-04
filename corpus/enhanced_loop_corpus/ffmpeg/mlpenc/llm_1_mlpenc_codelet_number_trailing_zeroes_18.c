#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t sample;
extern int bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1; outer++) {
        for (bits = 0; bits < 24 && !(sample & (1 << bits)); bits++) {
            // Inner loop performs the original bit check
        }
    }
}
