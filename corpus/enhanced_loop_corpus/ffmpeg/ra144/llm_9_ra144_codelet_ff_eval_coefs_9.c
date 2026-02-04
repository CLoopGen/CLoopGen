#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *coefs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 5; i++) {
    coefs[i * 2] >>= 4;
    coefs[i * 2 + 1] >>= 4;
}
}
