#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i < 80) {
    for (int k = i; k < 80 && ptr8[k] != ')'; k++) {
        *value++ = ptr8[k];
        i++; // Maintain update of outer 'i'
    }
}
}
