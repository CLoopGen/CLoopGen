#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal using a temporary array to enable sequential writes
    float temp[256];
    // Read in reverse from source
    for (i = 0; i < 256; i++) {
        temp[i] = window[703 - i];
    }
    // Write consecutively to destination
    for (i = 0; i < 256; i++) {
        window[2752 + i] = temp[i];
    }
}
