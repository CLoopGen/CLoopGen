#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *coefs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 20; i++) {
    coefs[i % 10] >>= 4;
    coefs[i % 10] += (coefs[i % 10] >> 2) - (coefs[i % 10] >> 1);
}
}
