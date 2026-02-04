#include <stdio.h>

#include <inttypes.h>

extern uint64_t w;
extern uint8_t *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t shift;
    for (i = 0; i < 16; i++) {
        shift = (i < 8) ? (8 * i) : (8 * (15 - i));
        p[i % 8] ^= (uint8_t)(w >> shift); // Use XOR to allow repeated access without zeroing
    }
}
