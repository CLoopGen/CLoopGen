#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int datlen;
extern int16_t *data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < datlen; i++) {
        uint8_t low = ((uint8_t *)(data + i))[0];
        uint8_t high = ((uint8_t *)(data + i))[1];
        data[i] = low + (high << 8); // Replaces multiplication with bit shift
    }
}
