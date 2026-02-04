#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *coefs;
extern int i;
extern int buffer2[10];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10; i++) {
        if (coefs[i] >= 0) {
            buffer2[i] = coefs[i];
        } else {
            buffer2[i] = 0;
        }
    }
}
