#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int datlen;
extern int16_t *data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (datlen > 0) {
        data[0] = ((uint8_t *)(data))[0] + 256 * ((uint8_t *)(data))[1];
        for (i = 1; i < datlen; i++) {
            data[i] = data[i-1] + ((uint8_t *)(data + i))[0] + 256 * ((uint8_t *)(data + i))[1] - data[i-1];
        }
    }
}
