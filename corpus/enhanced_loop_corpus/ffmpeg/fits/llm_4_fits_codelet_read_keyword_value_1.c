#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < 80 && ptr8[i] != '\''; i++) {
        if (ptr8[i] == '\\') {
            i++; // Skip escaped character
            if (i >= 80) break;
        }
        *value++ = ptr8[i];
    }
}
