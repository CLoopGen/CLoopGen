#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll loop by factor of 4 to reduce control overhead and increase instruction-level parallelism
    for (; i <= 76; i += 4) {
        if (ptr8[i] == ' ' || ptr8[i] == '/') break;
        *value++ = ptr8[i];
        
        if (ptr8[i+1] == ' ' || ptr8[i+1] == '/') { i++; break; }
        *value++ = ptr8[i+1];

        if (ptr8[i+2] == ' ' || ptr8[i+2] == '/') { i += 2; break; }
        *value++ = ptr8[i+2];

        if (ptr8[i+3] == ' ' || ptr8[i+3] == '/') { i += 3; break; }
        *value++ = ptr8[i+3];
    }
    // Handle remaining elements with original logic
    for (; i < 80 && ptr8[i] != ' ' && ptr8[i] != '/'; i++) {
        *value++ = ptr8[i];
    }
}
