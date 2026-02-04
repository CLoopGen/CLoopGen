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
if (p1 > 0) {
    for (i = 0; i < p1; i += 2) {
        *(uint16_t *)output = pix16;
        output += 2;
        if (i + 1 < p1) {
            *(uint16_t *)output = pix16;
            output += 2;
        }
    }
}
}
