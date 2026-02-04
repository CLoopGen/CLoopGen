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
        if (((uint8_t *)(data + i))[1] != 0)
            data[i] = ((uint8_t *)(data + i))[0] + 256 * ((uint8_t *)(data + i))[1];
        else
            data[i] = ((uint8_t *)(data + i))[0];
    }
}
