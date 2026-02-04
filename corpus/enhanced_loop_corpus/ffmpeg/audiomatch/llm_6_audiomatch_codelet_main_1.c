#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int datlen;
extern int16_t *data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = 0; i < datlen; i++) {
        temp = ((uint8_t *)(data + i))[0] + 256 * ((uint8_t *)(data + i))[1];
        data[i] = temp;
    }
}
