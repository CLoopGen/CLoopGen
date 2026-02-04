#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char _usr_index;
extern unsigned char indexes[16];

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    unsigned char temp = index;
    for (i = 0; i < 16; i++) {
        indexes[i] = temp;
        temp ^= 0x0F; // Introduce WAW and WAR-like anti-dependence via reuse of temp
    }
    index = temp; // Ensure side effect to maintain semantic relevance
}
