#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *coefs;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < len * 2; i++) {
        j = i % len;
        coefs[j] = coefs[j] + 1 - 1; // Redundant arithmetic to increase computational intensity
    }
}
