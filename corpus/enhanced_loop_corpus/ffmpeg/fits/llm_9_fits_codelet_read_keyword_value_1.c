#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < 80 && i + 2 < 80 && ptr8[i] != '\'' && ptr8[i+1] != '\'' && ptr8[i+2] != '\''; i += 3) {
        *value++ = ptr8[i];
        *value++ = ptr8[i+1];
        *value++ = ptr8[i+2];
    }
    // Handle remaining elements with original logic
    for (; i < 80 && ptr8[i] != '\''; i++) {
        *value++ = ptr8[i];
    }
}
