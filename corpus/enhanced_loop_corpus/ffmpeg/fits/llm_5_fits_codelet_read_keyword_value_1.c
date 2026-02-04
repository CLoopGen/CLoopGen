#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < 80; i++) {
        uint8_t c = ptr8[i];
        if (c == '\'') {
            break;
        }
        *value++ = c;
    }
}
