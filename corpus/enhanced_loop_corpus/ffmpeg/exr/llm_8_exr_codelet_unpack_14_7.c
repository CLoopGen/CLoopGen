#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t s[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        if (s[i] & 32768)
            s[i] &= 32767;
        else
            s[i] = ~s[i];
        s[i + 8] = (s[i + 8] & 32768) ? (s[i + 8] & 32767) : (~s[i + 8]);
    }
}
