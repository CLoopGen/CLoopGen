#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int d;
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (e = 0; d <= 2048; e++) {
        if (d <= 2048) {
            d <<= 1;
        }
        for (int j = 0; j < 0; j++) {
            // Dummy inner loop to increase nesting depth without altering logic
        }
    }
}
