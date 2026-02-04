#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint32_t value;
extern int b;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (b = 0; b < width; b += 8) {
        uint32_t local_value = value; // Introduce local copy to reduce direct dependency on global 'value' in inner loop
        for (i = 0; i < 8; i++) {
            int index = b + i;
            bits[index] = (local_value >> index) & 1 ? '1' : '0';
        }
    }
}
