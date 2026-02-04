#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile int dummy = 0;
    for (i = 0; len > 0; i++) {
        dummy += *(volatile char*)&len + i; // Simulate consecutive byte access over 'len' as if it were an array
        len >>= 8;
    }
}
