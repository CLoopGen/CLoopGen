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
int j;
for (j = 0; j < p1; j++) {
    for (i = 0; i < 1; i++) {
        *(uint32_t *)output = pix32;
        output += 4;
    }
}
}
