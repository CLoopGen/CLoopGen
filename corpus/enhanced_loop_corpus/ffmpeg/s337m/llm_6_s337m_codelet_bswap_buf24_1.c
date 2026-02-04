#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size / 3; i++, data += 3) {
        uint8_t temp1 = data[0];
        uint8_t temp2 = data[2];
        data[0] = temp2;
        data[2] = temp1;
    }
}
