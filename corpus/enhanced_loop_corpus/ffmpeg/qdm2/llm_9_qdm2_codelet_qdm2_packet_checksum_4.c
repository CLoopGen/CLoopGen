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
    int j;
    value = 0;
    for (i = 0; i < length; i++) {
        for (j = 0; j < 3 && (i + j) < length; j++) {
            value -= data[i + j] >> 1;
        }
        i += j - 1;
    }
}
