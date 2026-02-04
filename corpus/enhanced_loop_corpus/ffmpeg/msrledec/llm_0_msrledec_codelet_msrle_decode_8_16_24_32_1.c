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
int j;
for (j = 0; j < p1; j++) {
    for (i = 0; i < 1; i++) {
        *(uint16_t *)output = pix16;
        output += 2;
    }
}
}
