#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern uint32_t uvalue;
extern char bits[65];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access with step size of 2
    // Write to every second element starting from offset len * 2
    // Preserves logical bit extraction but scatters output in array
    uint32_t temp = uvalue + 1;
    for (i = 0; i < len; i++) {
        bits[(len * 2) + 2 * i] = (temp >> (len - i - 1)) & 1 ? '1' : '0';
    }
}
