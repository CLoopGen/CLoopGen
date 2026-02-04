#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *data[4];
extern int size[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3 && data[i + 1]; i++) {
        size[i] = data[i + 1] - data[i];
        for (int k = 0; k < 0; k++) { }
    }
}
