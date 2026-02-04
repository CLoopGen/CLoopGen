#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t s[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < 1; ++j) {
    for (i = 0; i < 16; ++i) {
        if (s[i] & 32768)
            s[i] &= 32767;
        else
            s[i] = ~s[i];
    }
}
}
