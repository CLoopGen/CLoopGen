#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int n;
extern uint8_t *samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < n / 4; outer++) {
        for (int inner = 0; inner < 4; inner++) {
            *samples++ = *src++ + 128;
        }
    }
    // Handle remaining elements if n is not a multiple of 4
    for (int remainder = 0; remainder < n % 4; remainder++) {
        *samples++ = *src++ + 128;
    }
    n = 0;
}
