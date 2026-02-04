#include <stdio.h>

#include <inttypes.h>

extern unsigned short *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short local_val = 100;
    for (i = 2; i < (6 + 3); i++) {
        *q++ = local_val;
        local_val ^= 0xFF; 
    }
}
