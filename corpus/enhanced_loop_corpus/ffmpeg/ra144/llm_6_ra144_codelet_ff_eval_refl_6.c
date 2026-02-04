#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *coefs;
extern int i;
extern int buffer2[10];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t temp[10];
    for (i = 0; i < 10; i++) {
        temp[i] = coefs[i];
        buffer2[i] = temp[i];
    }
}
