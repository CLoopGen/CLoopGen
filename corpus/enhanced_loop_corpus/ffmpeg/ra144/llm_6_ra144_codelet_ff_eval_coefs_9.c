#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *coefs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[10];
    for (i = 0; i < 10; i++) {
        temp[i] = coefs[i] >> 4;
    }
    for (i = 0; i < 10; i++) {
        coefs[i] = temp[i];
    }
}
