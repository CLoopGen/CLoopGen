#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *data;
extern int length;
extern int value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    value = 0;
    for (i = 0; i < length; i++) {
        if ((i & 1) == 0) {
            value -= data[i];
        }
    }
}
