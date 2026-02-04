#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *coefs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 9; i >= 0; i--) {
        if (i > 0) {
            coefs[i] = (coefs[i] + coefs[i-1]) >> 4;
        } else {
            coefs[i] >>= 4;
        }
    }
}
