#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t s[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 15; i >= 0; --i) {
        uint16_t temp = s[i];
        temp = ~temp;
        if (s[i] & 32768) {
            s[i] = s[i] & 32767;
        } else {
            s[i] = temp;
        }
        s[i] += (s[i] == 0) ? 1 : 0;
    }
}
