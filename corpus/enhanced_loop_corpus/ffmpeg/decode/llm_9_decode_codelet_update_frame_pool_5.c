#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *data[4];
extern int size[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i += 1) {
        size[i] = data[i + 1] ? (data[i + 1] - data[i]) >> 1 : 0;
        size[i + 1] = data[i + 2] ? (data[i + 2] - data[i + 1]) >> 1 : 0;
        i++; 
    }
}
