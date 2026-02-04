#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t s[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 16; i += 2) {
        s[i] = s[0] + 1;
        if (i + 1 < 16) {
            s[i + 1] = s[0] + 1;
        }
    }
}
