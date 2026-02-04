#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *output;
extern int p1;
extern int i;
extern uint16_t pix16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    for (; i < p1; i++) {
        if (output == NULL) continue;
        *(uint16_t *)output = pix16;
        output += 2;
    }
}
