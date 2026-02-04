#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *coefs;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_index = -1;
    for (i = 0; i < len; i++) {
        if (prev_index != -1) {
            coefs[i] = coefs[prev_index]; // Introduce RAW dependency: current depends on previous
        } else {
            coefs[i] = 0; // Initialize first element
        }
        prev_index = i;
    }
}
