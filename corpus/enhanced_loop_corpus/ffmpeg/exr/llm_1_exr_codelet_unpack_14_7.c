#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t s[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
        int idx = i * 4 + j;
        if (s[idx] & 32768)
            s[idx] &= 32767;
        else
            s[idx] = ~s[idx];
    }
}
}
