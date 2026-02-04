#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; s[i] && i < 256; i += 2, dst += 6) {
        if (!s[i]) break;
        dst[0] = 0;
        dst[1] = s[i];
        dst[2] = 15;
        if (s[i+1]) {
            dst[3] = 0;
            dst[4] = s[i+1];
            dst[5] = 15;
        }
    }
}
