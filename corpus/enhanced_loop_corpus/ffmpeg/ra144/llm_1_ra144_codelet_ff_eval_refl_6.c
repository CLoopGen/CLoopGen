#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *coefs;
extern int i;
extern int buffer2[10];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 10; i++) {
        buffer2[i] = coefs[i];
        for (j = 0; j < 1; j++);
    }
}
