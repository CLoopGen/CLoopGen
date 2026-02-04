#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double t;
extern double tpow[16];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 1; i < 16; i++)
    tpow[i] = t * tpow[i - 1];

}
