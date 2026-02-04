#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *buf;
extern int *charmap;
extern uint8_t *colram;
extern int a;
extern uint8_t temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Reverse Iteration
    // Access arrays in reverse order with a negative stride to alter memory access pattern
    // This changes temporal locality and may affect cache behavior
    for (a = 255; a >= 0; a--) {
        temp = colram[charmap[a + 0]] << 0;
        temp |= colram[charmap[a + 256]] << 1;
        temp |= colram[charmap[a + 512]] << 2;
        if (a < 232) {
            temp |= colram[charmap[a + 768]] << 3;
        } else {
            temp |= 0; // Ensure deterministic value when condition fails
        }
        buf[a] = temp << 2;
    }
}
