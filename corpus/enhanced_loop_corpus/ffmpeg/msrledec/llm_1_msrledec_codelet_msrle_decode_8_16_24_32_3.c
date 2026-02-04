#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *output;
extern int p1;
extern int i;
extern uint32_t pix32;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < p1; i += 2) {
    *(uint32_t *)output = pix32;
    output += 4;
    if (i + 1 < p1) {
        *(uint32_t *)output = pix32;
        output += 4;
    }
}
}
